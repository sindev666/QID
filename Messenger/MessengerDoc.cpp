
// MessengerDoc.cpp : implementation of the CMessengerDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Messenger.h"
#endif

#include "MessengerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMessengerDoc

IMPLEMENT_DYNCREATE(CMessengerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMessengerDoc, CDocument)
END_MESSAGE_MAP()


// CMessengerDoc construction/destruction

CMessengerDoc::CMessengerDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMessengerDoc::~CMessengerDoc()
{
}

typedef HRESULT (*DllGetClass)(
	REFCLSID rclsid,
	REFIID   riid,
	LPVOID* ppv
);

typedef test2::IPlugin* (*CreatePlugin)();

BOOL CMessengerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	CFileDialog libsel(TRUE, _T("dll"));
	libsel.AddEditBox(17, _T("Username"));
	if (libsel.DoModal() != IDOK)
		return FALSE;
	libsel.GetEditBoxText(17, username);
	libname = libsel.GetFolderPath() + _T("\\") + libsel.GetFileName();;
	hlib = LoadLibraryW(libname);
	if (hlib == NULL)
		return FALSE;
	CreatePlugin gc = (CreatePlugin)GetProcAddress(hlib, "CreateClassObject");
	if (gc == NULL)
		return FALSE;
	test2::IPlugin* ptr = gc();
	plugin = ptr;
	ptr->Release();
	return TRUE;
}




// CMessengerDoc serialization

void CMessengerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMessengerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMessengerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMessengerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMessengerDoc diagnostics

#ifdef _DEBUG
void CMessengerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMessengerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMessengerDoc commands


void CMessengerDoc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class
	if (hlib)
	{
		FreeLibrary(hlib);
	}

	CDocument::OnCloseDocument();
}
