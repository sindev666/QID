// app.cpp : This file contains the application class. Program execution begins and ends there.
//
#include "gui.h"
#include "guiMyFrame1.h"
#include "wx/wxprec.h"
#include "wx/fs_inet.h"
#include "wx/fs_mem.h"
#include "wx/fs_arc.h"
#include "wx/fs_zip.h"
#include "wx/stdpaths.h"
#include "wx/msgqueue.h"
#include "wx/webrequest.h"
#include "wx/splash.h"
#include "wx/fileconf.h"
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

// CHAT_ID, MSG_ID, RAW_MESSAGE_TEXT,HTML_MESSAGE_TEXT,DATETIME,USER_ID,USER_NAME,USER_SMALLPHOTO,TAG
typedef void(_cdecl* MESSAGE_RECIEVE_CALLBACK)(long long, long long, const wchar_t*, const wchar_t*, long long, long long, const wchar_t*, const wchar_t*, const wchar_t*, void*);
// USER_ID USER_FIRSTNAME USER_LASTNAME,USER_NICKNAME,USER_DESCRIPTION,USER_HTMLDESCRIPTION,USER_BIGPHOTO,USER_SMALLPHOTO
typedef void(_cdecl* USER_RECIEVE_CALLBACK)(long long, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, void*);
// CHAT_ID CHAT_NAME IS_DIALOG SMALLPHOTO BIGPHOTO CHAT_HTMLDESCRIPTION CHAT_LASTMESSAGE_TIME
typedef void(_cdecl* CHAT_RECIEVE_CALLBACK)(long long, const wchar_t*, long long, const wchar_t*, const wchar_t*, const wchar_t*, long long, void *);
// NOTIFICATION_HTML
typedef void(_cdecl* NOTIFICATION_RECIEVE_CALLBACK)(const wchar_t*);
// FINISH CALLBACK
typedef void(_cdecl* FINISH_CALLBACK)(void*);
// LOGIN API
typedef void (_cdecl *INIT_PROC)(const wchar_t* load_path);
typedef int (_cdecl* LOGIN_PROC)(char*);
// SETTINGS API
typedef wchar_t*(_cdecl* READ_SETTING)(const wchar_t* key);
typedef void(_cdecl* WRITE_SETTING)(const wchar_t* key, const wchar_t* value);
typedef void(_cdecl* ADD_USER_SETTING)(const wchar_t* key, const wchar_t* value, int tp);
// LOAD
typedef void(_cdecl* LOAD_PROC)(READ_SETTING, WRITE_SETTING);
typedef void(_cdecl* USER_PROC)(ADD_USER_SETTING);
typedef void(_cdecl* WRITE_USER_PROC)(const wchar_t* key, const wchar_t* value);
// SIGN FOR UPDATES
typedef void(*REGISTER_PROC)(NOTIFICATION_RECIEVE_CALLBACK, MESSAGE_RECIEVE_CALLBACK);
// DOWNLOAD FILE
typedef void(*DOWNLOAD_ASYNC)(const wchar_t* key, const wchar_t* path, FINISH_CALLBACK, void*);
typedef void(*LIST_CHATS_ASYNC)(CHAT_RECIEVE_CALLBACK, void*, FINISH_CALLBACK, void*);
typedef void(*LIST_MESSAGES_ASYNC)(long long chatid, long long offset, MESSAGE_RECIEVE_CALLBACK, void*, FINISH_CALLBACK, void*);
typedef void(*LIST_MEMBERS_ASYNC)(long long chatid, USER_RECIEVE_CALLBACK, void*, FINISH_CALLBACK, void*);
typedef void(*SEND_MESSAGE_ASYNC)(long long chatid, FINISH_CALLBACK, void*);
typedef void(*USER_INFO_ASYNC)(long long chatid, long long msgid, USER_RECIEVE_CALLBACK, void*);
typedef void(*BEGIN_DIALOG_ASYNC)(long long userid, CHAT_RECIEVE_CALLBACK, void*);
typedef void(*SEND_FILE_ASYNC)(long long chatid, const wchar_t* filepath, FINISH_CALLBACK, void*);

INIT_PROC qinit;
LOGIN_PROC qlogin;
LOAD_PROC qload;
REGISTER_PROC qregister;
DOWNLOAD_ASYNC qdownload;
LIST_CHATS_ASYNC qlist_chats;
LIST_MESSAGES_ASYNC qlist_messages;
LIST_MEMBERS_ASYNC qlist_members;
SEND_MESSAGE_ASYNC qsend_message;
USER_INFO_ASYNC quser_info;
BEGIN_DIALOG_ASYNC qbegin_dialog;
SEND_FILE_ASYNC qsend_file;
USER_PROC qget_user_settings;
WRITE_USER_PROC qset_user_settings;

void EmptyCallback(void*)
{
    // just do nothing
    // LOL
}

#define load(A, B) A = (decltype(A))GetProcAddress(hm, B); if (A == NULL) { wxMessageBox("QID SERVER ERROR - " B " not found", wxMessageBoxCaptionStr, wxICON_ERROR); return false; }

//typedef void(_cdecl* CALLBACK_PROC)(long long, void*);
//typedef void(_cdecl* RELEASE_PROC)(void*);
//typedef void(_cdecl* ENUMERATE_PROC)(CALLBACK_PROC);
//typedef int (_cdecl* GET_PROPERTY_INT)(int,void*);
//typedef void(_cdecl* GET_PROPERTY_STRING)(int, void*, wchar_t*);
//typedef long long(_cdecl* ENUMERATE_MESSAGES_PROC)(CALLBACK_PROC, long long);
//
//typedef void(_cdecl* POPUP_PROC)(const wchar_t*);
//
//typedef void(_cdecl* REGISTER_PROC)(CALLBACK_PROC, POPUP_PROC);
//
//typedef int(_cdecl* SYNCHRONIZE_PROC)(const wchar_t*, wchar_t*, bool);
//
//typedef void(_cdecl* BEGIN_DOWNLOAD_PROC)(const wchar_t*, const wchar_t*);
//
//typedef void(_cdecl* ENUMERATE_PARTICIPANTS_PROC)(long long, CALLBACK_PROC);
//
//INIT_PROC qid_init = 0, qid_keep_alive;
//LOGIN_PROC qid_login;
//RELEASE_PROC qid_delete;
//ENUMERATE_PROC qid_get_chats, qid_get_dialogs;
//GET_PROPERTY_INT qid_get_chat_info, qid_get_message_info, qid_get_plugin_info,qid_get_user_info;
//GET_PROPERTY_STRING qid_get_chat_infos, qid_get_message_infos, qid_get_plugin_infos, qid_get_user_infos;
//ENUMERATE_MESSAGES_PROC qid_get_messages;
//REGISTER_PROC qid_register;
//BEGIN_DOWNLOAD_PROC qid_download;
//ENUMERATE_PARTICIPANTS_PROC qid_get_participants;
//
//
//enum ChatInfo_Properties
//{
//    CHAT_NAME,
//    CHAT_BIGPHOTO,
//    CHAT_SMALLPHOTO,
//    CHAT_DESCRIPTION1,
//    CHAT_FULL_DESCRIPTION,
//    CHAT_TYPE,
//    CHAT_ID
//};
//
//enum MessageInfo_Properties
//{
//    MESSAGE_FROM_ID,
//    MESSAGE_FROM_NAME,
//    MESSAGE_FROM_PHOTO,
//    MESSAGE_TEXT_RAW,
//    MESSAGE_TEXT_HTML,
//    MESSAGE_FILE_COUNT,
//    MESSAGE_PHOTO_PREVIEW_COUNT,
//    MESSAGE_VIDEO_PREVIEW_COUNT,
//    MESSAGE_REPLY_ID,
//    MESSAGE_FIRST_FILE = 1000,
//    MESSAGE_FIRST_PHOTO_PREVIEW=2000,
//    MESSAGE_FIRST_VIDEO_PREVIEW=3000
//};
//
//enum UserInfo_Properties
//{
//    USER_NAME,
//    USER_DIALOG_ID,
//    USER_ID,
//    USED_DESCRIPTION,
//    USER_SMALLPHOTO,
//    USER_BIGPHOTO,
//    USER_FULL_DESCRIPTION
//};

char buf[1024];

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

    wxFileName rootpath;
    //wxBaseConfig* globconf;
};

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
wxIMPLEMENT_APP(MyApp);


wchar_t buff[1024];

wchar_t* ReadIni(const wchar_t* key)
{
    /*wxFileName fn = wxGetApp().rootpath;
    wxString username = fn.GetDirs().back();
    fn.RemoveLastDir();
    fn.SetName(username);
    fn.SetExt("ini");
    memset(buf, 0, sizeof(buf));
    buf[GetPrivateProfileStringW(L"qid", key, L"", buff, 1023, fn.GetFullPath())] = 0;
    return buff;*/
    wxStrcpy(buff, wxConfigBase::Get()->Read(key));
    return buff;
}

void WriteIni(const wchar_t* key, const wchar_t* value)
{
    /*wxFileName fn = wxGetApp().rootpath;
    wxString username = fn.GetDirs().back();
    fn.RemoveLastDir();
    fn.SetName(username);
    fn.SetExt("ini");
    WritePrivateProfileStringW(L"qid", key, value, fn.GetFullPath());*/
    wxConfigBase::Get()->Write(key, value);
    wxConfigBase::Get()->Flush();
}

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
            lib_phone->Append(s);
            s = fs.FindNext();
        }
        lib_layout->Add(lib_phone, wxSizerFlags().Center().Border());
        wxButton* lib_continue = new wxButton(lib_choose, wxID_OK, "OK");
        
        //lib_layout->Add(lib_choose);
        lib_layout->Add(lib_continue, wxSizerFlags().Center().Border());
        lib_choose->SetSizerAndFit(lib_layout);
        ss->HideWithEffect(wxShowEffect::wxSHOW_EFFECT_ROLL_TO_RIGHT);
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
    wxMilliSleep(350);
    load(qlogin, "login");
    load(qinit, "init");
    load(qbegin_dialog, "begin_dialog");
    load(qdownload, "download");
    load(qlist_chats, "list_chats");
    load(qlist_members, "list_members");
    load(qlist_messages, "get_messages");
    load(qload, "load_settings");
    load(qregister, "register");
    load(qsend_file, "send_file");
    load(qsend_message, "send_message");
    load(quser_info, "user_info");
    load(qget_user_settings, "get_user");
    load(qset_user_settings, "set_user");
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd2_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    wxFileName fn(wxStandardPaths::Get().GetUserDataDir(), "");
    fn.AppendDir(username);
    if (!fn.DirExists())
        fn.Mkdir();
    rootpath = fn;
    fn.RemoveLastDir();
    fn.SetName(username);
    fn.SetExt("ini");
    if (!fn.Exists())
    {
        wxFile f(fn.GetFullPath(), wxFile::write);
        f.Close();
    }
    wxConfigBase::Set(new wxFileConfig("QID", "FANTOM", fn.GetFullPath()));
    qload(ReadIni, WriteIni);
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd3_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    qinit(rootpath.GetFullPath());
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd4_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    // load settings
    strcpy_s(buf, username);
    int t = qlogin(buf);
    while (t != 0)
    {
        ss->Hide();
        if (t == 1)
        {
            wxPasswordEntryDialog dlg(NULL, buf);
            if (dlg.ShowModal() != wxID_OK)
            {
                return false;
            }
            strcpy_s(buf, dlg.GetValue());
        }
        else
        {
            wxTextEntryDialog dlg(NULL, buf);
            if (dlg.ShowModal() != wxID_OK)
            {
                return false;
            }
            strcpy_s(buf, dlg.GetValue());
        }
        ss->Show();
        t = qlogin(buf);
    }
    wxMilliSleep(150);
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd5_xpm), wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_NO_TIMEOUT, 0, NULL, -1);
    ss->Show();
    wxMilliSleep(150);
    // create frame
    guiMyFrame1* frame = new guiMyFrame1(NULL);
    frame->Show();
    ss->Hide();
    ss = new wxSplashScreen(wxImage(qid_wnd6_xpm), wxSPLASH_CENTRE_ON_PARENT, 5000, frame, -1);
    ss->Show();
    //wxMessageBox(dll_name);
    //wxMessageBox(username);
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

guiMyFrame1::guiMyFrame1(wxWindow* parent)
    :
    MyFrame1(parent)
{
    //winUsers->SetFont(wxFont())
    //winChat->SetBackgroundImage(wxImage("as.jpg"));
    //winChat->SetPage("<html><body background=\"as.jpg\">Mike: This is my text<blockquote>11:20</blockquote><br></body></html>");
}

void guiMyFrame1::OnSearch(wxCommandEvent& event)
{
    // TODO: Implement OnSearch
}

void guiMyFrame1::GoBack(wxCommandEvent& event)
{
    // TODO: Implement GoBack
}

void guiMyFrame1::OpenSettings(wxCommandEvent& event)
{
    // TODO: Implement OpenSettings

}

void guiMyFrame1::OnCellClicked(wxHtmlCellEvent& event)
{
    // TODO: Implement OnCellClicked
}

void guiMyFrame1::OnLinkClicked(wxHtmlLinkEvent& event)
{
    // TODO: Implement OnLinkClicked
    
}

void guiMyFrame1::OnFileSend(wxCommandEvent& event)
{
    // TODO: Implement OnFileSend
}

void guiMyFrame1::OnEmojiSelect(wxCommandEvent& event)
{
    // TODO: Implement OnEmojiSelect
}

void guiMyFrame1::OnPasteImageAndFile(wxKeyEvent& event)
{
    // TODO: Implement OnPasteImageAndFile
    event.Skip();
}

void guiMyFrame1::OnSendMessage(wxCommandEvent& event)
{
    // TODO: Implement OnSendMessage
    //event.Skip();
}
