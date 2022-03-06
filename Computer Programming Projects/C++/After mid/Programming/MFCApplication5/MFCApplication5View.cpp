
// MFCApplication5View.cpp : implementation of the CMFCApplication5View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CEditView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication5View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication5View construction/destruction

CMFCApplication5View::CMFCApplication5View()
{
	// TODO: add construction code here

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CMFCApplication5View printing


void CMFCApplication5View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMFCApplication5View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMFCApplication5View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CMFCApplication5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication5View diagnostics

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CEditView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View message handlers
