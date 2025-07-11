// WelcomeView.cpp : implementation file
//
// Copyright(C) 2025 sindev666
//
// This program is free software : you can redistribute it and /or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see < https://www.gnu.org/licenses/ >.

#include "pch.h"
#include "Messenger.h"
#include "WelcomeView.h"


// CWelcomeView

IMPLEMENT_DYNCREATE(CWelcomeView, CView)

CWelcomeView::CWelcomeView()
{
	EnableD2DSupport();

}

CWelcomeView::~CWelcomeView()
{
}

BEGIN_MESSAGE_MAP(CWelcomeView, CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CWelcomeView drawing

void CWelcomeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	CRenderTarget* rt = GetRenderTarget();
	rt->BeginDraw();
	rt->Clear(rt->COLORREF_TO_D2DCOLOR(RGB(255, 255, 255)));
	rt->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE::D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE);
	D2D1_GRADIENT_STOP gs[3] = { {0,rt->COLORREF_TO_D2DCOLOR(RGB(0,255,0))},{0.5,rt->COLORREF_TO_D2DCOLOR(RGB(0,0,255))},{1.0,rt->COLORREF_TO_D2DCOLOR(RGB(255,0,0)) } };
	CD2DBrush* br = new CD2DLinearGradientBrush(rt, gs, 3, { {0.0,0.0},{328.0,24.0} });
	rt->DrawTextLayout({ 0.0,0.0 }, new CD2DTextLayout(rt, _T("Welcome to QID Messenger!"), CD2DTextFormat(rt, _T("Arial"), 24.0), { 620,24 }), br);
	br = new CD2DSolidColorBrush(rt, rt->COLORREF_TO_D2DCOLOR(RGB(0, 0, 0)));
	rt->DrawTextLayout({ 0.0,24.0 }, new CD2DTextLayout(rt, _T("To begin talking, please press File > New File"), CD2DTextFormat(rt, _T("Arial"), 16.0), { 620,24 }), br);
	rt->EndDraw();
}


// CWelcomeView diagnostics

#ifdef _DEBUG
void CWelcomeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CWelcomeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CWelcomeView message handlers


int CWelcomeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
