using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using TL;

namespace test2
{
    [ComVisible(true)]
    [Guid("7ACDB243-D728-46A8-88D2-9AF909AB9BCD")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IWatch
    {
        void Report(int status);
    }

    [ComVisible(true)]
    [Guid("83BCAF21-33FD-4EB7-9F61-466E93E2CDA3")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IDownloadable
    {
        string FileHash { get; }

        void BeginDownload(IWatch watch, string out_filename);
    }

    [ComVisible(true)]
    [Guid("D9E52E4E-090A-4552-9971-599149BAAD53")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IChat
    {
        string Name { get; }

        long ChatID { get; }

        bool IsDialog { get; }

        IDownloadable BigChatPhoto { get; }

        IDownloadable SmallChatPhoto { get; }

        void GetAllUsers();

        string UserName { get; }

        ICollection AllowedReactions { get; }

        string Link { get; }

        bool Muted { get; set; }

        void GetMessages(long offset);

        void AddUserToChat(IUser user);

        void RemoveUserFromChat(IUser user);

        string Description { get; set; }

        bool IsPinned { get; set; }

        bool SupportTags { get; }

        bool MessagesAllowed { get; }

        long UnreadCount { get; }

        IMessage LastMessage { get; }
    }

    [ComVisible(true)]
    [Guid("FC6AAF14-EED1-4851-844F-71929471CE91")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IPhoto
    {
        IDownloadable File { get; }

        IDownloadable Preview { get; }
    }

    [ComVisible(true)]
    [Guid("A9E79A78-66A8-4163-8AB4-F7262B1EDFE3")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IAlbum
    {
        int Length { get; }

        IPhoto GetPhoto(int id);
    }

    [ComVisible(true)]
    [Guid("9A3E1C44-753B-4AF9-979F-E57CC482209A")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IAttachment
    {
        int Length { get; }

        string OriginalName { get; }

        IDownloadable File { get; }
    }

    [ComVisible(true)]
    [Guid("809640C1-9B7B-4D87-8D3F-A19FB6DF0F87")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface ICollection
    {
        int Length { get; }

        object GetItem(int id);
    }

    [ComVisible(true)]
    [Guid("6B3CAC3B-14FF-45BE-A8AA-BF200A4E9FF9")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface ISetting
    {
        string UserName { get; }

        string Value { get; set; }

        int Type { get; }
    }

    [ComVisible(true)]
    [Guid("C2E2978F-F459-40CF-A75F-3BA01DE44ADE")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IReaction
    {
        long Count { get; }
        string Value { get; }
    }

    [ComVisible(true)]
    [Guid("9797A406-0E0C-4066-AF8B-1DDE6796AC23")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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

        string Tag { get; }

        DateTime SendDate { get; }

        DateTime EditDate { get; }
    }

    [ComVisible(true)]
    [Guid("7FB77966-0256-4E79-9EF0-D2C6F1BC2AD1")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IPollAnswer
    {
        string Value { get; }

        int VotesCount { get; }

        void Vote();

        bool HaveVoted { get; }

        void Revote();
    }

    [ComVisible(true)]
    [Guid("BC376410-1255-47E7-A880-68A5FC89D664")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IPoll : IMessage
    {
        ICollection Answers { get; }

        bool CanMultipleVote { get; }

        bool CanRevote { get; }


    }

    [ComVisible(true)]
    [Guid("E4313071-378A-4124-96B1-35F34D23B18C")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IUserMessage : IMessage
    {
        void Delete();

        void Edit(string text);

        bool HasBeenRead { get; }

        DateTime ReadTime { get; }
    }

    [ComVisible(true)]
    [Guid("C33AD7AB-899E-4CE8-B89D-36C53CA72BBF")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IClient
    {
        void WriteUserData(string a, string b);

        string ReadUserData(string a);

        void ShowNotificationDialog(ref string html, int dlg_type);

        void OnNewChat(IChat chat);

        void OnUserChanged(long chat_id, IUser user, bool isTyping, bool isOnline, bool isAdmin, bool isParticipant);

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
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
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

        void SendSimpleMessage(IChat chat, string text, long reply_id, string tag_name);

        void SendFileMessage(IChat chat, string filename, long reply_id, string tag_name);

        void SendAlbumMessage(IChat chat, ICollection photos_filenames, long reply_id, string tag_name);

        void ForwardMessage(IMessage message, IChat target);

        void ConsoleMessage(string command);

        void OnAction(long chat_id, long msg_id, string action);

        void CreatePoll(IChat chat, string question, string type, ICollection answers);
    }

    class CommonClientFunctions
    {
        IClient Client { get; set; }
        internal CommonClientFunctions(IClient client)
        {
            Client = client;
        }

        internal void AddPropertyInt(string name, int def_value)
        {
            string cur = Client.ReadUserData(name);
            _ = int.TryParse(cur, out def_value);
            Client.WriteUserData(name, def_value.ToString());
            SendCommand("add_property", new List<object> { name, def_value });
        }

        internal void AddPropertyString(string name, string def_value)
        {
            string cur = Client.ReadUserData(name);
            if (cur != "")
                def_value = cur;
            else
                Client.WriteUserData(name, def_value);
            SendCommand("add_property", new List<object> { name, def_value });
        }

        internal void AddPropertySelect2(string name, string a, string b)
        {
            string cur = Client.ReadUserData(name);
            if (cur == b)
            {
                string c = b;
                b = a;
                a = c;
            }
            Client.WriteUserData(name, a);
            SendCommand("add_property", new List<object> { name, new List<object> { a, b } });
        }

        internal void AddPropertySelect(string name, List<string> options)
        {
            string cur = Client.ReadUserData(name);
            List<object> res = new List<object>();
            foreach (var item in options)
            {
                if (item == cur)
                {
                    res.Add(item);
                }
            }
            foreach (var item in options)
            {
                if (item != cur)
                {
                    res.Add(item);
                }
            }
            Client.WriteUserData(name, res.First().ToString());
            SendCommand("add_property", new List<object> { name, res });
        }

        private void ImplementObject(object x, ref string res)
        {
            if (x == null)
            {
                res += "object!null";
                return;
            }
            if (x is List<object> ts)
            {
                res += "{";
                foreach (var item in ts)
                {
                    res += item.GetType().Name;
                    res += "!";
                    ImplementObject(item, ref res);
                    res += ";";
                }
                res += "object!null";
                res += "}";
            }
            else
            {
                res += x.ToString();
            }
        }

        private void SendCommand(string v, List<object> ts)
        {
            string cmd = "$[sysprog]@" + v;
            ImplementObject(ts, ref cmd);
            Client.ConsoleMessage(cmd);
        }
    }

    [ComVisible(true)]
    [Guid("01EC9A28-AEB8-49AA-9246-CB96B220C886")]
    [ProgId("test2.Main")]
    public class A : IPlugin
    {
        WTelegram.Client client;
        WTelegram.UpdateManager Manager;

        static Assembly _Load(string path)
        {
            if (!File.Exists(path)) return null;

            Console.WriteLine("Load: " + path);
            return Assembly.LoadFrom(path);
        }

        public A()
        {
            AppDomain.CurrentDomain.AssemblyResolve += (sender, args) =>
        _Load(Path.Combine
        (
            Path.GetDirectoryName(typeof(A).Assembly.Location),
            args.Name?.Remove(args.Name.IndexOf(',')) + ".dll"
        ));
            //client = new WTelegram.Client(17349, "344583e45741c457fe1862106095a5eb");


        }

        public IClient Client { get; set; }

        public void ConsoleMessage(string command)
        {
            throw new NotImplementedException();
        }

        public void CreatePoll(IChat chat, string question, string type, ICollection answers)
        {
            throw new NotImplementedException();
        }

        public void ForwardMessage(IMessage message, IChat target)
        {
            throw new NotImplementedException();
        }

        public void GetAllChats()
        {
            if (Client == null)
            {
                throw new NotSupportedException();
            }
            _ = getChats();
        }

        private async Task getChats()
        {
            var res = await client.Messages_GetAllDialogs();
            foreach (var item in res.Dialogs)
            {
                if (item is Dialog ch)
                {
                    //var x = await client.Messages_GetMessages(new InputMessageID { id = item.TopMessage });
                    //x.Messages[0];
                    //MessageService ms;
                    //ms.action;
                    
                }
            }
        }

        public IChat GetChatByUsername(string username)
        {
            throw new NotImplementedException();
        }

        public ICollection GetContacts()
        {
            throw new NotImplementedException();
        }

        public IUser GetUserByUsername(string username)
        {
            throw new NotImplementedException();
        }

        public void Init(string settings_path)
        {
            if (Client == null)
                throw new NotSupportedException();
            CommonClientFunctions ccf = new CommonClientFunctions(Client);
            ccf.AddPropertySelect2("Test mode", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Disable advertise", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Disable edit updates", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Disable delete updates", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Disable read callbacks", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Disable AD telemetry", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Auto send telemetry - watch AD", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Auto send telemetry - click AD", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Suppress Telegram TOS warning at startup", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Allow openning unsupported chats", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Allow viewing unsupported messages", "Off", "On");
            ccf.AddPropertySelect2("Experiemental/Allow direct commands DONT ENABLE THIS UNLESS YOU SURE WHAT ARE YOU DOING", "Off", "On");
            ccf.AddPropertyInt("Experiemental/Ping timeout", 0);
            ccf.AddPropertySelect2("Security/Disallow deleting chats", "On", "Off");
            ccf.AddPropertySelect2("Security/Disallow deleting messages", "On", "Off");
            ccf.AddPropertySelect2("Security/Disallow editing messages", "On", "Off");
            ccf.AddPropertySelect2("Security/Disallow sending messages", "Off", "On");
            ccf.AddPropertySelect2("View/Show messages as plain text", "Off", "On");
            ccf.AddPropertySelect2("View/Show messages in MD format", "Off", "On");
            ccf.AddPropertySelect2("View/Disable emoticons", "Off", "On");
            ccf.AddPropertySelect2("View/Disable reactions", "Off", "On");
            ccf.AddPropertySelect2("View/Disable videos", "Off", "On");
            ccf.AddPropertySelect2("View/Disable images", "Off", "On");
            ccf.AddPropertyString("HTTP Proxy", "");
            ccf.AddPropertyString("SOCKS5 Proxy", "");
            ccf.AddPropertyString("MTProto Proxy", "");
            ccf.AddPropertyInt("Telegram API/Id", 17349);
            ccf.AddPropertyString("Telegram API/Token", "344583e45741c457fe1862106095a5eb");
            if (Client.ReadUserData("Test mode") == "On")
            {
                client = new WTelegram.Client(s =>
                {
                    switch (s)
                    {
                        case "api_id": return Client.ReadUserData("Telegram API/Id");
                        case "api_hash": return Client.ReadUserData("Telegram API/Token");
                        case "server_address": return "2>149.154.167.40:443"; // test DC
                        case "session_path": return settings_path;
                        default:
                            return null;
                    }
                });
            }
            else
            {
                client = new WTelegram.Client(int.Parse(Client.ReadUserData("Telegram API/Id")), Client.ReadUserData("Telegram API/Token"), settings_path);
            }
            if (Client.ReadUserData("HTTP Proxy") != "")
            {
                string s = Client.ReadUserData("HTTP Proxy");
                if (s.IndexOf(':') == -1)
                {
                    client.TcpHandler = async (address, port) =>
                    {
                        var proxy = new Starksoft.Net.Proxy.HttpProxyClient(s);
                        //var proxy = xNet.Socks5ProxyClient.Parse("host:port:username:password");
                        await Task.Delay(TimeSpan.FromMilliseconds(1));
                        return proxy.CreateConnection(address, port);
                    };                    
                }
                else
                {
                    string host = s.Substring(0, s.IndexOf(':'));
                    if (!int.TryParse(s.Substring(s.IndexOf(':') + 1), out int mport))
                        mport = 1080;
                    client.TcpHandler = async (address, port) =>
                    {
                        var proxy = new Starksoft.Net.Proxy.HttpProxyClient(host, mport);
                        //var proxy = xNet.Socks5ProxyClient.Parse("host:port:username:password");
                        await Task.Delay(TimeSpan.FromMilliseconds(1));
                        return proxy.CreateConnection(address, port);
                    };
                }
                
            }
            if (Client.ReadUserData("SOCKS5 Proxy") != "")
            {
                string s = Client.ReadUserData("SOCKS5 Proxy");
                string host = s.Substring(0, s.IndexOf(':'));
                if (!int.TryParse(s.Substring(s.IndexOf(':')+1), out int mport))
                {
                    mport = 1080;
                }
                client.TcpHandler = async (address, port) =>
                {
                    var proxy = new Starksoft.Net.Proxy.Socks5ProxyClient(host, mport);
                    //var proxy = xNet.Socks5ProxyClient.Parse("host:port:username:password");
                    await Task.Delay(TimeSpan.FromMilliseconds(1));
                    return proxy.CreateConnection(address, port);
                };
            }
            if (Client.ReadUserData("MTProto Proxy") != "")
            {
                client.MTProxyUrl = Client.ReadUserData("MTProto Proxy");
            }
            if (int.TryParse(Client.ReadUserData("Experiemental/Ping timeout"), out int ping))
            {
                client.PingInterval = ping;
            }
        }

        public int Login(ref string user_data)
        {
            //throw new NotImplementedException();
            Task<string> res = client.Login(user_data);
            res.Wait(1500);
            if (!res.IsCompleted)
                throw new NotSupportedException();
            if (client.User != null)
            {
                user_data = "Connected as " + client.User.username;
                Manager = client.WithUpdateManager(OnUpdate);
                return 0;
            }
            if (res.Result == "")
                return 0;
            user_data = res.Result;
            if (res.Result == "verification_code" || res.Result == "password")
                return 2;
            return 1;
        }

        private async Task OnUpdate(Update update)
        {
            switch (update)
            {
               // case UpdateNewMessage unm: await HandleMessage(unm.message); break;
                //case UpdateEditMessage uem: await HandleMessage(uem.message, true); break;
                // Note: UpdateNewChannelMessage and UpdateEditChannelMessage are also handled by above cases
                //case UpdateDeleteChannelMessages udcm: Console.WriteLine($"{udcm.messages.Length} message(s) deleted in {Chat(udcm.channel_id)}"); break;
                //case UpdateDeleteMessages udm: Console.WriteLine($"{udm.messages.Length} message(s) deleted"); break;
                //case UpdateUserTyping uut: Console.WriteLine($"{User(uut.user_id)} is {uut.action}"); break;
                //case UpdateChatUserTyping ucut: Console.WriteLine($"{Peer(ucut.from_id)} is {ucut.action} in {Chat(ucut.chat_id)}"); break;
                //case UpdateChannelUserTyping ucut2: Console.WriteLine($"{Peer(ucut2.from_id)} is {ucut2.action} in {Chat(ucut2.channel_id)}"); break;
                //case UpdateChatParticipants { participants: ChatParticipants cp }: Console.WriteLine($"{cp.participants.Length} participants in {Chat(cp.chat_id)}"); break;
                //case UpdateUserStatus uus: Console.WriteLine($"{User(uus.user_id)} is now {uus.status.GetType().Name[10..]}"); break;
                //case UpdateUserName uun: Console.WriteLine($"{User(uun.user_id)} has changed profile name: {uun.first_name} {uun.last_name}"); break;
                //case UpdateUser uu: Console.WriteLine($"{User(uu.user_id)} has changed infos/photo"); break;
                default: Client.ConsoleMessage(update.GetType().Name); break; // there are much more update types than the above example cases
            }
            
        }

        public void OnAction(long chat_id, long msg_id, string action)
        {
            throw new NotImplementedException();
        }

        public object ParseLink(string link)
        {
            throw new NotImplementedException();
        }

        public void SearchMessages(string text)
        {
            throw new NotImplementedException();
        }

        public void SearchWeb(string text)
        {
            throw new NotImplementedException();
        }

        public void SendAlbumMessage(IChat chat, ICollection photos_filenames, long reply_id, string tag_name)
        {
            throw new NotImplementedException();
        }

        public void SendFileMessage(IChat chat, string filename, long reply_id, string tag_name)
        {
            throw new NotImplementedException();
        }

        public void SendSimpleMessage(IChat chat, string text, long reply_id, string tag_name)
        {
            throw new NotImplementedException();
        }
    }
    //static class B
    //{
    //    [DllExport]
    //    static public IntPtr CreateClassObject()
    //    {

    //        return Marshal.GetComInterfaceForObject(new A(), typeof(IPlugin));
    //    }
    //}

}
