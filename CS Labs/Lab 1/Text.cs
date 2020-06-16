using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Write_Text
{
    public class Class_Write_Text
    {
        public void Text_1()
        {
            Console.WriteLine("\nКомпьютер подключен к сети. Нужно искать решение дальше");
        }

        public void Text_2()
        {
            Console.WriteLine("\nК сожалению сын не может помочь: он пошёл играть в футбол");
        }
        public void Text_3()
        {
            try
            {
                int FirstValue;

                Console.WriteLine("\nОткрыв крышку вы вспомнили, что недавно сын менял видеокарту и заодно почистил компьютер");

                do
                {
                    Console.WriteLine("\n1\tПроверить подключение видеокарты" +
                        "\n2\tПроверить подключение комплектующих к блоку питания" +
                        "\n0\tНазад");
                    FirstValue = int.Parse(Console.ReadLine());

                    switch (FirstValue)
                    {
                        case 1:
                            Console.WriteLine("\nВидеокарта подключена верно. И дело не в ней, так как ПК вообще не включается");
                            break;
                        case 2:
                            Console.WriteLine("\nМатеринская плата была плохо подключена к болоку питания. " +
                                "Вы переподключили кабель, теперь можно работать");
                            Environment.Exit(0);
                            break;
                        default:
                            break;
                    }

                } while (FirstValue != 0);
            }
            catch
            {
                Console.WriteLine("Ошибка. Неверный формат ввода");
            }
        }
    }
}
