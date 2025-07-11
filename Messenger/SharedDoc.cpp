// SharedDoc.cpp : implementation file
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
#include "SharedDoc.h"


// CSharedDoc

IMPLEMENT_DYNCREATE(CSharedDoc, CDocument)

CSharedDoc::CSharedDoc()
{
}

BOOL CSharedDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	shrd_data = 0;
	shrd_obj = 0;
	return TRUE;
}

CSharedDoc::~CSharedDoc()
{
}


BEGIN_MESSAGE_MAP(CSharedDoc, CDocument)
END_MESSAGE_MAP()


// CSharedDoc diagnostics

#ifdef _DEBUG
void CSharedDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CSharedDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CSharedDoc serialization

void CSharedDoc::Serialize(CArchive& ar)
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
#endif


// CSharedDoc commands


void CSharedDoc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class
	if (shrd_obj)
	{
		delete shrd_obj;
	}

	CDocument::OnCloseDocument();
}
