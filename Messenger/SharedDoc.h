#pragma once

// CSharedDoc document

class CSharedDoc : public CDocument
{
	DECLARE_DYNCREATE(CSharedDoc)

public:
	int* shrd_data;
	void* shrd_obj;
	CSharedDoc();
	virtual ~CSharedDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnCloseDocument();
};
