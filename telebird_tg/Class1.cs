using RGiesecke.DllExport;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace telebird_tg
{
    public class Class1
    {
        public void TEST()
        {
            //await client.Messages_GetAllChats();
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            Console.WriteLine("HI! FROM C#");
        }
        public async Task LOL()
        {
            WTelegram.Client client = new WTelegram.Client(123, "YOUR_API_HASH");
            var t = await client.Messages_GetAllChats();
            //t.chats[234].Photo;
            var f = await client.GetMessages(t.chats[123].ToInputPeer());
            
        }

        //[DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        //public void init()
        //{
        //    TEST();
            
        //}
    }
}
