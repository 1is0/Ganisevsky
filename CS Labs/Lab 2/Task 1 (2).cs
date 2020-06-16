using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    public class Class_Task1
    {
        public void Task1_2()
        {
            try
            {
                int Ctr;
                do
                {
                    Console.WriteLine("\nEnter some words");

                    string sentence = Console.ReadLine();
                    string[] words = sentence.Split(' ');//расщепляет на слова
                    Console.WriteLine("\nreversed:\n");
                    Array.Reverse(words);

                    for (int i = 0; i < words.Length; i++)
                    {
                        Console.Write(words[i] + " ");
                    }

                    Console.WriteLine("\n\nExit?\n" +
                        "1 — yes\n" +
                        "0 — no");
                    Ctr = int.Parse(Console.ReadLine());

                } while (Ctr == 0);
            }
            catch
            {
                Console.WriteLine("Error");
            }
        }
    }
}
