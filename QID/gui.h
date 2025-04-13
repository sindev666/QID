///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/srchctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/html/htmlwin.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/bmpbuttn.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxSearchCtrl* m_searchCtrl1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel1;
		wxHtmlWindow* winUsers;
		wxPanel* m_panel4;
		wxSplitterWindow* m_splitter5;
		wxPanel* m_panel5;
		wxHtmlWindow* winChat;
		wxPanel* m_panel6;
		wxHtmlWindow* winInfo;
		wxBitmapButton* m_bpButton2;
		wxBitmapButton* m_bpButton3;
		wxTextCtrl* m_textCtrl1;
		wxBitmapButton* m_bpButton1;

		// Virtual event handlers, override them in your derived class
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void GoBack( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCellClicked( wxHtmlCellEvent& event ) { event.Skip(); }
		virtual void OnLinkClicked( wxHtmlLinkEvent& event ) { event.Skip(); }
		virtual void OnFileSend( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEmojiSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPasteImageAndFile( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnSendMessage( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 122 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MyFrame1::m_splitter1OnIdle ), NULL, this );
		}

		void m_splitter5OnIdle( wxIdleEvent& )
		{
			m_splitter5->SetSashPosition( 0 );
			m_splitter5->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MyFrame1::m_splitter5OnIdle ), NULL, this );
		}

};

