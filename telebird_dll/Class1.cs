using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace telebird_dll
{

    static public class A
    {
        static WTelegram.Client client;

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void init(IntPtr x)
        {
            //string cur = Marshal.PtrToStringUni(x);
            //if (cur != "")
            //    cur += "session.dat";
            client = new WTelegram.Client(17349, "344583e45741c457fe1862106095a5eb");
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static int login(IntPtr x)
        {
            //LOL().Wait();
            //UnmanagedString str;
            Task<string> tmp = client.Login(Marshal.PtrToStringAnsi(x));
            tmp.Wait();
            //tmp.Result
            string s = tmp.Result;
            for (int i = 0; i < Math.Min(1023, s.Length); i++)
            {
                Marshal.WriteByte(x, i, (byte)s[i]);
            }
            Marshal.WriteByte(x, Math.Min(1023, s.Length), (byte)0);
            return (s == "" ? 0 : (s == "verification_code" || s == "password" ? 1 : 2));
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void begin_dialog(Int64 chat, IntPtr callback, IntPtr token)
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void download()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void list_chats()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void list_members()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void get_messages()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void load_settings()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void register()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void send_file()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void send_message()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void user_info()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void get_user()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void set_user()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }
    }
}
