using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace ConsoleApp1
{
    class ProgramFileIO
    {
        static void Main(string[] args)
        {
            int RestartProgram = 0;

            do
            {

                Console.WriteLine("***** Simple I/O with the File Type *****\n”); string[] myTasks = { "Fix bathroom sink", "Call Dave", "Call Mom and Dad", "Play Xbox One"};
                // Записать все данные в файл на диске С: .
                File.WnteAllLines(@"tasks . txt", myTasks) ;
                // Прочитать все данные и вывести на консоль.
                foreach (string task in File.ReadAllLines(@"tasks.txt"))
                {
                    Console.WriteLine("TODO: {0}", task);
                }
                Console.ReadLine();

            } while (RestartProgram == 1);
        }
    }
}