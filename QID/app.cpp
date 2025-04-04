// app.cpp : This file contains the application class. Program execution begins and ends there.
//
#include "gui.h"
#include "wx/wxprec.h"
#include "wx/fs_inet.h"
#include "wx/fs_mem.h"
#include "wx/fs_arc.h"
#include "wx/fs_zip.h"
#include "wx/stdpaths.h"
#include "wx/msgqueue.h"
#include "wx/webrequest.h"
#include "wx/splash.h"
#include "wx/dir.h"
#include "QID_MAIN.h"
#include "QID_WND1.h"
#include "QID_WND2.h"
#include "QID_WND3.h"
#include "QID_WND4.h"
#include "QID_WND5.h"
#include "QID_WND6.h"

/*
* void init void
* int login(char[256])
* int enumerate_all_chats callback_proc
* void enumerate_chat_messages
* void register_update_callback message_callback notification_callback
* get_chat_info
* get_chat_participants
* enumerate_all_dialogs
*/

typedef void (_cdecl *INIT_PROC)(void);
typedef int (_cdecl* LOGIN_PROC)(char*);
typedef void(_cdecl* CALLBACK_PROC)(long long, void*);
typedef void(_cdecl* RELEASE_PROC)(void*);
typedef void(_cdecl* ENUMERATE_PROC)(CALLBACK_PROC);
typedef int (_cdecl* GET_PROPERTY_INT)(int,void*);
typedef void(_cdecl* GET_PROPERTY_STRING)(int, void*, wchar_t*);
typedef long long(_cdecl* ENUMERATE_MESSAGES_PROC)(CALLBACK_PROC, long long);

typedef void(_cdecl* POPUP_PROC)(const wchar_t*);

typedef void(_cdecl* REGISTER_PROC)(CALLBACK_PROC, POPUP_PROC);

typedef int(_cdecl* SYNCHRONIZE_PROC)(const wchar_t*, wchar_t*, bool);

typedef void(_cdecl* BEGIN_DOWNLOAD_PROC)(const wchar_t*, const wchar_t*);

typedef void(_cdecl* ENUMERATE_PARTICIPANTS_PROC)(long long, CALLBACK_PROC);

INIT_PROC qid_init, qid_keep_alive;
LOGIN_PROC qid_login;
RELEASE_PROC qid_delete;
ENUMERATE_PROC qid_get_chats, qid_get_dialogs;
GET_PROPERTY_INT qid_get_chat_info, qid_get_message_info, qid_get_plugin_info,qid_get_user_info;
GET_PROPERTY_STRING qid_get_chat_infos, qid_get_message_infos, qid_get_plugin_infos, qid_get_user_infos;
ENUMERATE_MESSAGES_PROC qid_get_messages;
REGISTER_PROC qid_register;
BEGIN_DOWNLOAD_PROC qid_download;
ENUMERATE_PARTICIPANTS_PROC qid_get_participants;


enum ChatInfo_Properties
{
    CHAT_NAME,
    CHAT_BIGPHOTO,
    CHAT_SMALLPHOTO,
    CHAT_DESCRIPTION1,
    CHAT_FULL_DESCRIPTION,
    CHAT_TYPE,
    CHAT_ID
};

enum MessageInfo_Properties
{
    MESSAGE_FROM_ID,
    MESSAGE_FROM_NAME,
    MESSAGE_FROM_PHOTO,
    MESSAGE_TEXT_RAW,
    MESSAGE_TEXT_HTML,
    MESSAGE_FILE_COUNT,
    MESSAGE_PHOTO_PREVIEW_COUNT,
    MESSAGE_VIDEO_PREVIEW_COUNT,
    MESSAGE_REPLY_ID,
    MESSAGE_FIRST_FILE = 1000,
    MESSAGE_FIRST_PHOTO_PREVIEW=2000,
    MESSAGE_FIRST_VIDEO_PREVIEW=3000
};

enum UserInfo_Properties
{
    USER_NAME,
    USER_DIALOG_ID,
    USER_ID,
    USED_DESCRIPTION,
    USER_SMALLPHOTO,
    USER_BIGPHOTO,
    USER_FULL_DESCRIPTION
};

//typedef 

    /*extern "C" __declspec(dllexport) void update_callback()
    {
        wxMessageBox("LOL");
    }*/

//struct qid_msginfo
//{
//    enum qid_operation
//    {
//        QID_GET_CHATS,
//        QID_GET_DIALOGS,
//        QID_GET_CHAT_INFO,
//        QID_GET_CHAT_PARTICIPANTS,
//        QID_GET_CHAT_STATUS,
//        QID_DOWNLOAD_FILE,
//        QID_DOWNLOAD_PHOTO,
//        QID_DOWNLOAD_MESSAGES
//    } oper;
//    wxEvent* onFinish;
//};
//
////wxMessageQueue<
//void _cdecl qid_loop(HMODULE hm)
//{
//
//}

// Define a new application type, each program should derive a class from wxApp
class MyApp : public wxApp
{
public:
    // override base class virtuals
    // ----------------------------

    // this one is called on application startup and is a good place for the app
    // initialization (doing it here and not in the ctor allows to have an error
    // return: if OnInit() returns false, the application terminates)
    virtual bool OnInit() override;
};

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
wxIMPLEMENT_APP(MyApp);

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
    // call the base class initialization method, currently it only parses a
    // few common command-line options but it could be do more in the future
    if (!wxApp::OnInit())
        return false;
    wxSplashScreen* ss = new wxSplashScreen(wxImage(qid_main_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->ShowWithEffect(wxShowEffect::wxSHOW_EFFECT_EXPAND);
    wxFileSystem::AddHandler(new wxArchiveFSHandler());
    wxFileSystem::AddHandler(new wxMemoryFSHandler());
    wxFileSystem::AddHandler(new wxInternetFSHandler());
    wxInitAllImageHandlers();
    wxString dll_name, username;
    if (!wxDir::Exists(wxStandardPaths::Get().GetUserDataDir()))
    {
        wxDir::Make(wxStandardPaths::Get().GetUserDataDir());
    }
    wxSleep(2);
    ss->HideWithEffect(wxShowEffect::wxSHOW_EFFECT_ROLL_TO_RIGHT);
    {
        wxDialog* lib_choose = new wxDialog(NULL, -1, "QID 1.0");
        wxBoxSizer* lib_layout = new wxBoxSizer(wxVERTICAL);
        wxStaticText* lib_first = new wxStaticText(lib_choose, -1, "Please select QID server DLL to continue");
        lib_layout->Add(lib_first, wxSizerFlags().Center().Border());
        wxComboBox* lib_dll = new wxComboBox(lib_choose, -1);
        lib_dll->SetEditable(false);
        wxFileSystem fs;
        fs.ChangePathTo(wxStandardPaths::Get().GetExecutablePath());
        wxString s = fs.FindFirst("*.dll");
        while (s != "")
        {
            s = fs.URLToFileName(s).GetName();
            lib_dll->Append(s);
            s = fs.FindNext();
        }
        lib_layout->Add(lib_dll, wxSizerFlags().Center().Border());
        wxStaticText* lib_second = new wxStaticText(lib_choose, -1, "Please select username to continue");
        lib_layout->Add(lib_second, wxSizerFlags().Center().Border());
        wxComboBox* lib_phone = new wxComboBox(lib_choose, -1);
        lib_phone->SetEditable(true);
        fs.ChangePathTo(wxStandardPaths::Get().GetUserDataDir(), true);
        s = fs.FindFirst("*.ini");
        while (s != "")
        {
            s = fs.URLToFileName(s).GetName();
            s.RemoveLast(4);
            lib_dll->Append(s);
            s = fs.FindNext();
        }
        lib_layout->Add(lib_phone, wxSizerFlags().Center().Border());
        wxButton* lib_continue = new wxButton(lib_choose, wxID_OK, "OK");
        
        //lib_layout->Add(lib_choose);
        lib_layout->Add(lib_continue, wxSizerFlags().Center().Border());
        lib_choose->SetSizerAndFit(lib_layout);
        if (lib_choose->ShowModal() != wxID_OK)
            return false;
        dll_name = lib_dll->GetStringSelection() + ".dll";
        username = lib_phone->GetValue();
        delete lib_choose;
    }
    ss = new wxSplashScreen(wxImage(qid_wnd1_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    HMODULE hm = LoadLibraryW(dll_name);
    if (hm == NULL)
    {
        wxMessageBox("QID SERVER ERROR - LoadLibraryW failed", wxMessageBoxCaptionStr, wxICON_ERROR);
        return false;
    }
    qid_init = (INIT_PROC)GetProcAddress(hm, "init");
    if (qid_init==NULL)
    {
        wxMessageBox("QID SERVER ERROR - init not found", wxMessageBoxCaptionStr, wxICON_ERROR);
        return false;
    }
    qid_keep_alive = (INIT_PROC)GetProcAddress(hm, "loop");
    /*if (qid_keep_alive == NULL)
    {
        wxMessageBox("QID SERVER ERROR - loop not found", wxMessageBoxCaptionStr, wxICON_ERROR);
        return false;
    }*/
    wxMilliSleep(350);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd2_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    qid_init();
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd3_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    //qid_keep_alive();
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd4_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    // load settings
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd5_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    wxMilliSleep(150);
    // create frame
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd6_xpm), wxSPLASH_CENTRE_ON_PARENT, 0, NULL, -1);
    ss->Show();
    wxMessageBox(dll_name);
    wxMessageBox(username);
    // create the main application window
    //MyFrame1* frame = new MyFrame1(NULL, wxID_ANY, "Your application");

    // and show it (the frames, unlike simple controls, are not shown when
    // created initially)
    //frame->Show(true);

    // success: wxApp::OnRun() will be called which will enter the main message
    // loop and the application will run. If we returned false here, the
    // application would exit immediately.
    return true;
}