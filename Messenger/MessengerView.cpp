
// MessengerView.cpp : implementation of the CMessengerView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Messenger.h"
#endif

#include "MessengerDoc.h"
#include "MessengerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessengerView

IMPLEMENT_DYNCREATE(CMessengerView, CView)

BEGIN_MESSAGE_MAP(CMessengerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMessengerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMessengerView construction/destruction

CMessengerView::CMessengerView() noexcept
{
	// TODO: add construction code here

}

CMessengerView::~CMessengerView()
{
}

BOOL CMessengerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMessengerView drawing

void CMessengerView::OnDraw(CDC* /*pDC*/)
{
	CMessengerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	//test2::IWatchPtr watch;
	//_com_ptr_t c;
}


// CMessengerView printing


void CMessengerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMessengerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMessengerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMessengerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMessengerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMessengerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMessengerView diagnostics

#ifdef _DEBUG
void CMessengerView::AssertValid() const
{
	CView::AssertValid();
}

void CMessengerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessengerDoc* CMessengerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessengerDoc)));
	return (CMessengerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessengerView message handlers
