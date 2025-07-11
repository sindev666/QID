#pragma once


// CWelcomeView view

class CWelcomeView : public CView
{
	DECLARE_DYNCREATE(CWelcomeView)

protected:
	CWelcomeView();           // protected constructor used by dynamic creation
	virtual ~CWelcomeView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


