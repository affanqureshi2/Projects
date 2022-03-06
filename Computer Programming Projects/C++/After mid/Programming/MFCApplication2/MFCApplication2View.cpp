
// MFCApplication2View.cpp : implementation of the CMFCApplication2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CEditView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplication2View construction/destruction

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: add construction code here

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CMFCApplication2View printing

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMFCApplication2View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CMFCApplication2View diagnostics

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CEditView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View message handlers
