using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp
{
    class Program
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            JoyConNative.Manager m = new JoyConNative.Manager();

            List<JoyConNative.Controler> list;
            do
            {
                list = m.ScanForDevices();
            } while (list.Count == 0);

            Console.WriteLine("First");
            foreach (var j in list)
            {
                Console.WriteLine(j.Type);
            }

            var list2 = m.ScanForDevices();

            Console.WriteLine("seccond");
            foreach (var j in list2)
            {
                Console.WriteLine(j.Type);
            }

            foreach (var j in list.Concat(list2))
            {
                j.SetHCIState(JoyConNative.HCIState.Disconnect);
            }

            Console.WriteLine("Press Key to continue.");
            Console.ReadKey(true);
        }
    }
}
