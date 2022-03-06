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

// MFCApplication4View.h : interface of the CMFCApplication4View class
//

#pragma once

#include "resource.h"


class CMFCApplication4View : public CFormView
{
protected: // create from serialization only
	CMFCApplication4View();
	DECLARE_DYNCREATE(CMFCApplication4View)

public:
	enum{ IDD = IDD_MFCAPPLICATION4_FORM };

// Attributes
public:
	CMFCApplication4Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedList1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedCheck1();
};

#ifndef _DEBUG  // debug version in MFCApplication4View.cpp
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

