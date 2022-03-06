
// MFCApplication2Doc.cpp : implementation of the CMFCApplication2Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication2Doc

IMPLEMENT_DYNCREATE(CMFCApplication2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication2Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication2Doc construction/destruction

CMFCApplication2Doc::CMFCApplication2Doc()
{
	// TODO: add one-time construction code here

}

CMFCApplication2Doc::~CMFCApplication2Doc()
{
}

BOOL CMFCApplication2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);
	}

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCApplication2Doc serialization

void CMFCApplication2Doc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != NULL)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCApplication2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCApplication2Doc::InitializeSearchContent()
{
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// Use the entire text file content as the search content.
	SetSearchContent(m_strSearchContent);
}

void CMFCApplication2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication2Doc diagnostics

#ifdef _DEBUG
void CMFCApplication2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication2Doc commands
