using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace test2
{
    [ComVisible(true)]
    [Guid("7ACDB243-D728-46A8-88D2-9AF909AB9BCD")]
    public interface IWatch
    {
        void Report(int status);
    }

    [ComVisible(true)]
    [Guid("83BCAF21-33FD-4EB7-9F61-466E93E2CDA3")]
    public interface IDownloadable
    {
        string FileHash { get; }

        void BeginDownload(IWatch watch, string out_filename);
    }

    [ComVisible(true)]
    [Guid("D9E52E4E-090A-4552-9971-599149BAAD53")]
    public interface IChat
    {
        string Name { get; }

        long ChatID { get; }

        bool IsDialog { get; }

        IDownloadable BigChatPhoto { get; }

        IDownloadable SmallChatPhoto { get; }

        ICollection Users { get; }

        string UserName { get; }

        ICollection AllowedReactions { get; }

        string Link { get; }

        bool Muted { get; set; }

        void GetMessages(long offset);

        void AddUserToChat(IUser user);

        void RemoveUserFromChat(IUser user);

        string Description { get; set; }
    }

    [ComVisible(true)]
    [Guid("FC6AAF14-EED1-4851-844F-71929471CE91")]
    public interface IPhoto
    {
        IDownloadable File { get; }

        IDownloadable Preview { get; }
    }

    [ComVisible(true)]
    [Guid("A9E79A78-66A8-4163-8AB4-F7262B1EDFE3")]
    public interface IAlbum
    {
        int Length { get; }

        IPhoto GetPhoto(int id);
    }

    [ComVisible(true)]
    [Guid("9A3E1C44-753B-4AF9-979F-E57CC482209A")]
    public interface IAttachment
    {
        int Length { get; }

        string OriginalName { get; }

        IDownloadable File { get; }
    }

    [ComVisible(true)]
    [Guid("809640C1-9B7B-4D87-8D3F-A19FB6DF0F87")]
    public interface ICollection
    {
        int Length { get; }

        object GetItem(int id);
    }

    [ComVisible(true)]
    [Guid("6B3CAC3B-14FF-45BE-A8AA-BF200A4E9FF9")]
    public interface IADvertise
    {
        IPhoto Photo { get; }

        string Title { get; }

        string Description { get; }

        string Link { get; }

        void Metricks_View(string Metricks_Hash, string Metricks_App, string Metricks_Source);

        void Metricks_Click(string Metricks_Hash, string Metricks_App, string Metricks_Source, int x, int y);

        void Metricks_Close(string Metricks_Hash, string Metricks_App, string Metricks_Source);

        void Metricks_MouseOver(string Metricks_Hash, string Metricks_App, string Metricks_Source, int x, int y);
    }

    [ComVisible(true)]
    [Guid("16A5A0A0-24B3-4FF4-8941-7C4DFDD1CE32")]
    public interface ISetting
    {
        string UserName { get; }

        string Value { get; set; }

        int Type { get; }
    }

    [ComVisible(true)]
    [Guid("C2E2978F-F459-40CF-A75F-3BA01DE44ADE")]
    public interface IReaction
    {
        long Count { get; }
        string Value { get; }
    }

    [ComVisible(true)]
    [Guid("9797A406-0E0C-4066-AF8B-1DDE6796AC23")]
    public interface IUser
    {
        IAlbum ProfilePhoto { get; }

        string Username { get; }

        long Id { get; }

        string RealName { get; }

        string Description { get; }

        IChat StartChatWithUser();

        bool GetIsUserOnline();

        string Link { get; }
    }

    [ComVisible(true)]
    [Guid("3F31040D-2CB0-4B11-AAC4-20C2E6DBF8DD")]
    public interface IMessage
    {
        IAttachment File { get; }

        string HTMLMessage { get; }

        IAlbum Album { get; }

        IUser From { get; }

        IChat Chat { get; }

        ICollection Reactions { get; }

        long Id { get; }

        long ReplyId { get; }
    }

    [ComVisible(true)]
    [Guid("E4313071-378A-4124-96B1-35F34D23B18C")]
    public interface IUserMessage : IMessage
    {
        void Delete();

        void Edit(string text);
    }

    [ComVisible(true)]
    [Guid("C33AD7AB-899E-4CE8-B89D-36C53CA72BBF")]
    public interface IClient
    {
        void WriteUserData(string a, string b);

        string ReadUserData(string a);

        void ShowNotificationDialog(ref string html, int dlg_type);

        void OnNewChat(IChat chat);

        void OnNewMessage(long chat_id, IMessage message);

        void OnMessageChanged(long chat_id, long msg_id, IMessage message);

        void OnSearchResult(IDownloadable photo, string title, string description, string link);

        void OnReactionChanged(long chat_id, long msg_id, string react, int diff);

        void UserDefinedMessageAction(long chat_id, long msg_id, string action_name);

        void ShowAdvertise(long chat_id, IADvertise advertise);

        void LogMessage(int tp, string content);

        void ConsoleMessage(string content);
    }

    [ComVisible(true)]
    [Guid("42CF4999-3DE9-4046-9FA3-7A9492B6185A")]
    public interface IPlugin
    {
        void Init(string settings_path);

        int Login(ref string user_data);

        IClient Client { get; set; }

        void GetAllChats();

        ICollection GetContacts();

        IUser GetUserByUsername(string username);

        IChat GetChatByUsername(string username);

        object ParseLink(string link);

        void SearchMessages(string text);

        void SearchWeb(string text);

        void SendSimpleMessage(IChat chat, string text, long reply_id);

        void SendFileMessage(IChat chat, string filename, long reply_id);

        void SendAlbumMessage(IChat chat, ICollection photos_filenames, long reply_id);

        void ForwardMessage(IMessage message, IChat target);

        void ConsoleMessage(string command);
    }
    //[ComVisible(true)]
    //[Guid("01EC9A28-AEB8-49AA-9246-CB96B220C886")]
    //[ProgId("test2.Main")]
    //public class A : IPlugin
    //{
    //    WTelegram.Client client;

    //    public A()
    //    {
    //        //client = new WTelegram.Client();
            
            
    //    }
    //}
}
