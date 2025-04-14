
// MessengerDoc.h : interface of the CMessengerDoc class
//


#pragma once


class CMessengerDoc : public CDocument
{
protected: // create from serialization only
	CMessengerDoc() noexcept;
	DECLARE_DYNCREATE(CMessengerDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMessengerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	HMODULE hlib = NULL;
	CString libname, username;
	CComPtr<test2::IPlugin> plugin;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void OnCloseDocument();
};
