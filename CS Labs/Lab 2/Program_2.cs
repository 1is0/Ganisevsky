using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task_1;

namespace Lab_2
{
    class Program_2
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Choose program:\n" +
                                "1 — Task 1 (2)\n" +
                                "2 — Task 2 ( )\n" +
                                "3 — Task 3 ( )\n" +
                                "0 — Exit");

                int MenuItem = int.Parse(Console.ReadLine());
                Class_Task1 class_t1 = new Class_Task1();
                switch (MenuItem)
                {
                    case 1:
                        class_t1.Task1_2();
                        break;
                    case 0:
                        Environment.Exit(0);
                        break;
                    default:
                        break;
                }



            }
            catch
            {
                Console.WriteLine("Error");
            }
        }
    }
}
