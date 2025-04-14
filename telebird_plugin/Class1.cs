using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace telebird_plugin
{
    public class Class1
    {
        static Assembly _Load(string path)
        {
            if (!File.Exists(path)) return null;

            Console.WriteLine("Load: " + path);
            return Assembly.LoadFrom(path);
        }
        [DllExport]
        static public IntPtr CreateClassObject()
        {
            AppDomain.CurrentDomain.AssemblyResolve += (sender, args) =>
        _Load(Path.Combine
        (
            Path.GetDirectoryName(typeof(Class1).Assembly.Location),
            args.Name?.Remove(args.Name.IndexOf(',')) + ".dll"
        ));
            return Marshal.GetComInterfaceForObject(new test2.A(), typeof(test2.IPlugin));
        }
    }
}
