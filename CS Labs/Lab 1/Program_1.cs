using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Windows.Forms;
using Write_Text;

namespace ConsoleApp1
{
    class Program_1
    {
        static void Main(string[] args)
        {
            try
            {
                int FirstValue;
                Class_Write_Text write_Text = new Class_Write_Text();

                Console.WriteLine("Добро пожаловать в текстовый квест." +
                    "\nВы решили поработать за компьютером, но после нажатия кнопки питания он не включается. " +
                    "Что же делать?");

                do
                {
                    Console.WriteLine("\n\n1\t— Может я снова забыл его подключить?\n\tПроверить подключен ли ПК к электросети\n" +
                        "\n2\t— Что он опять натворил с компьютером?\n\tПопросить помощи у сына\n" +
                        "\n3\t— Попробую разобраться сам\n\tОткрыть корпус ПК и разобраться в чём дело\n" +
                        "\n0\tВыход из программы");
                    FirstValue = int.Parse(Console.ReadLine());

                    switch (FirstValue)
                    {
                        case 1:
                            write_Text.Text_1();
                            break;
                        case 2:
                            write_Text.Text_2();
                            break;
                        case 3:
                            write_Text.Text_3();
                            break;
                        case 0:
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