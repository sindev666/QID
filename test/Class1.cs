using System.Runtime.InteropServices;

namespace test
{
    public class Class1
    {
        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void init()
        {
            //LOL().Wait();

        }
    }
}
