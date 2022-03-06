
// MFCApplication6View.cpp : implementation of the CMFCApplication6View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CEditView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplication6View construction/destruction

CMFCApplication6View::CMFCApplication6View()
{
	// TODO: add construction code here

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CMFCApplication6View printing

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMFCApplication6View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CMFCApplication6View diagnostics

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CEditView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View message handlers
