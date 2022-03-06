
// MFCApplication6View.h : interface of the CMFCApplication6View class
//

#pragma once


class CMFCApplication6View : public CEditView
{
protected: // create from serialization only
	CMFCApplication6View();
	DECLARE_DYNCREATE(CMFCApplication6View)

// Attributes
public:
	CMFCApplication6Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApplication6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApplication6View.cpp
inline CMFCApplication6Doc* CMFCApplication6View::GetDocument() const
   { return reinterpret_cast<CMFCApplication6Doc*>(m_pDocument); }
#endif

