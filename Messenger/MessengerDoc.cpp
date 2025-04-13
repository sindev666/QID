
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

BEGIN_DISPATCH_MAP(CMessengerDoc, CDocument)
END_DISPATCH_MAP()

// Note: we add support for IID_IMessenger to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .IDL file.

// {7c5f2e3c-7bd0-4641-acaf-c816f4b66973}
static const IID IID_IMessenger =
{0x7c5f2e3c,0x7bd0,0x4641,{0xac,0xaf,0xc8,0x16,0xf4,0xb6,0x69,0x73}};

BEGIN_INTERFACE_MAP(CMessengerDoc, CDocument)
	INTERFACE_PART(CMessengerDoc, IID_IMessenger, Dispatch)
END_INTERFACE_MAP()


// CMessengerDoc construction/destruction

CMessengerDoc::CMessengerDoc() noexcept
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CMessengerDoc::~CMessengerDoc()
{
	AfxOleUnlockApp();
}

BOOL CMessengerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

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
