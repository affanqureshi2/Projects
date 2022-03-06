// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MFCApplication4View.cpp : implementation of the CMFCApplication4View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CFormView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCApplication4View construction/destruction

CMFCApplication4View::CMFCApplication4View()
	: CFormView(CMFCApplication4View::IDD)
{
	// TODO: add construction code here

}

CMFCApplication4View::~CMFCApplication4View()
{
}

void CMFCApplication4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMFCApplication4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMFCApplication4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication4View diagnostics

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View message handlers


void CMFCApplication4View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}
