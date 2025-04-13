///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"
#include "icon1.h"
#include "icon2.h"
#include "icon3.h"
#include "icon_left.h"
#include "icon_settings.h"

///////////////////////////////////////////////////////////////////////////

wxImage ConvertXPM(static const char* const* XPM, int x)
{
	wxImage img(XPM);
	float a = img.GetWidth(), b = img.GetHeight();
	float t = (a < b ? a : b) / x;
	img.Rescale(a / t, b / t);
	return img;
}

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_searchCtrl1 = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_searchCtrl1->ShowSearchButton( true );
	#endif
	m_searchCtrl1->ShowCancelButton( true );
	bSizer2->Add( m_searchCtrl1, 1, wxALL | wxEXPAND, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetBitmap(ConvertXPM(icon_left,24));
	bSizer2->Add( m_button2, 0, wxALL, 0 );

	m_button3 = new wxButton( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->SetBitmap(ConvertXPM(icon_settings,24));
	bSizer2->Add( m_button3, 0, wxALL, 0 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( MyFrame1::m_splitter1OnIdle ), NULL, this );

	m_panel1 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	winUsers = new wxHtmlWindow( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer3->Add( winUsers, 1, wxALL|wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_panel4 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_splitter5 = new wxSplitterWindow( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter5->Connect( wxEVT_IDLE, wxIdleEventHandler( MyFrame1::m_splitter5OnIdle ), NULL, this );

	m_panel5 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	winChat = new wxHtmlWindow( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer5->Add( winChat, 1, wxALL|wxEXPAND, 0 );


	m_panel5->SetSizer( bSizer5 );
	m_panel5->Layout();
	bSizer5->Fit( m_panel5 );
	m_panel6 = new wxPanel( m_splitter5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	winInfo = new wxHtmlWindow( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer6->Add( winInfo, 1, wxALL|wxEXPAND, 0 );


	m_panel6->SetSizer( bSizer6 );
	m_panel6->Layout();
	bSizer6->Fit( m_panel6 );
	m_splitter5->SplitVertically( m_panel5, m_panel6, 0 );
	bSizer4->Add( m_splitter5, 1, wxALL|wxEXPAND, 5 );


	bSizer8->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_bpButton2 = new wxBitmapButton( m_panel4, wxID_ANY, icon_file, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	bSizer7->Add( m_bpButton2, 0, wxALL, 1 );

	m_bpButton3 = new wxBitmapButton( m_panel4, wxID_ANY, icon_emoji, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	bSizer7->Add( m_bpButton3, 0, wxALL, 1 );

	m_textCtrl1 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_MULTILINE|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH );
	bSizer7->Add( m_textCtrl1, 1, wxALL|wxEXPAND, 4 );

	m_bpButton1 = new wxBitmapButton( m_panel4, wxID_ANY, icon_send, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	bSizer7->Add( m_bpButton1, 0, wxALL, 1 );


	bSizer8->Add( bSizer7, 0, wxEXPAND, 0 );


	m_panel4->SetSizer( bSizer8 );
	m_panel4->Layout();
	bSizer8->Fit( m_panel4 );
	m_splitter1->SplitVertically( m_panel1, m_panel4, 122 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_searchCtrl1->Connect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( MyFrame1::OnSearch ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::GoBack ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OpenSettings ), NULL, this );
	winUsers->Connect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winUsers->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	winChat->Connect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winChat->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	winInfo->Connect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winInfo->Connect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	m_bpButton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnFileSend ), NULL, this );
	m_bpButton3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnEmojiSelect ), NULL, this );
	m_textCtrl1->Connect( wxEVT_CHAR_HOOK, wxKeyEventHandler( MyFrame1::OnPasteImageAndFile ), NULL, this );
	m_textCtrl1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame1::OnSendMessage ), NULL, this );
	m_bpButton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSendMessage ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_searchCtrl1->Disconnect( wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN, wxCommandEventHandler( MyFrame1::OnSearch ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::GoBack ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OpenSettings ), NULL, this );
	winUsers->Disconnect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winUsers->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	winChat->Disconnect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winChat->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	winInfo->Disconnect( wxEVT_COMMAND_HTML_CELL_CLICKED, wxHtmlCellEventHandler( MyFrame1::OnCellClicked ), NULL, this );
	winInfo->Disconnect( wxEVT_COMMAND_HTML_LINK_CLICKED, wxHtmlLinkEventHandler( MyFrame1::OnLinkClicked ), NULL, this );
	m_bpButton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnFileSend ), NULL, this );
	m_bpButton3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnEmojiSelect ), NULL, this );
	m_textCtrl1->Disconnect( wxEVT_CHAR_HOOK, wxKeyEventHandler( MyFrame1::OnPasteImageAndFile ), NULL, this );
	m_textCtrl1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame1::OnSendMessage ), NULL, this );
	m_bpButton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::OnSendMessage ), NULL, this );

}
