
// MFCApplication1Doc.cpp : implementation of the CMFCApplication1Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1Doc

IMPLEMENT_DYNCREATE(CMFCApplication1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication1Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication1Doc construction/destruction

CMFCApplication1Doc::CMFCApplication1Doc()
{
	// TODO: add one-time construction code here

}

CMFCApplication1Doc::~CMFCApplication1Doc()
{
}

BOOL CMFCApplication1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCApplication1Doc serialization

void CMFCApplication1Doc::Serialize(CArchive& ar)
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
void CMFCApplication1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFCApplication1Doc::InitializeSearchContent()
{
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// Use the entire text file content as the search content.
	SetSearchContent(m_strSearchContent);
}

void CMFCApplication1Doc::SetSearchContent(const CString& value)
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

// CMFCApplication1Doc diagnostics

#ifdef _DEBUG
void CMFCApplication1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication1Doc commands
