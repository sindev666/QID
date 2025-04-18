#ifndef __guiMyFrame1__
#define __guiMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "gui.h"

//// end generated include

/** Implementing MyFrame1 */
class guiMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void OnSearch( wxCommandEvent& event );
		void GoBack( wxCommandEvent& event );
		void OpenSettings( wxCommandEvent& event );
		void OnCellClicked( wxHtmlCellEvent& event );
		void OnLinkClicked( wxHtmlLinkEvent& event );
		void OnFileSend( wxCommandEvent& event );
		void OnEmojiSelect( wxCommandEvent& event );
		void OnPasteImageAndFile( wxKeyEvent& event );
		void OnSendMessage( wxCommandEvent& event );
	public:
		/** Constructor */
		guiMyFrame1( wxWindow* parent );
	//// end generated class members
		
};

#endif // __guiMyFrame1__
