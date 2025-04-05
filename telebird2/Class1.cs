using RGiesecke.DllExport;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace telebird2
{
    public class Class1
    {
        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void init()
        {
            //LOL().Wait();
            //UnmanagedString str;
        }
    }
}
