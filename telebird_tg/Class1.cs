
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using TL;

namespace telebird_tg
{
    static class A
    {
        static WTelegram.Client client;

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void init()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }
    }
    public static class Class1
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public delegate void INIT();
        public static void TEST()
        {
            //await client.Messages_GetAllChats();
            //Console.ForegroundColor = ConsoleColor.DarkGreen;
            //Console.WriteLine("HI! FROM C#");
            Thread.Sleep(20000);
        }
        public static async Task LOL()
        {
            WTelegram.Client client = new WTelegram.Client(17349, "344583e45741c457fe1862106095a5eb");
            var t = await client.Messages_GetAllChats();
            ////t.chats[234].Photo;
            var f = await client.GetMessages(t.chats[123].ToInputPeer());
            //var s = await client.Users_GetFullUser(new InputPeerChannel(0, 2));
            

        }

        public static void Main()
        {
            //plugin_init(Marshal.GetFunctionPointerForDelegate((INIT)TEST));
        }

        [UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public delegate string Notification(string value);

        //[UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
    }
    
}
