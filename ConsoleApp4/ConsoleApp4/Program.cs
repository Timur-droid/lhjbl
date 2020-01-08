using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            Zadania.zadanie1();
            Console.WriteLine("\n\n\t Задание 2");
            Zadania.zadanie2();
            Console.WriteLine("\n\n\t Задание 3");
            Zadania.zadanie3();
            Console.WriteLine("\n\n\t Задание 4");
            Zadania.zadanie4();
            Console.WriteLine("\n\n\t Задание 5");
            Zadania.zadanie5();
            Console.WriteLine("Конец");
        }
    }
    class Zadania
    {
        //--------------1 Задание-------
        public static void zadanie1()
        {
            Console.WriteLine("Введите предложение!");
            Console.WriteLine("Не забудьте поставить '.'");
            int probels = 0;
            char a = '0';
            while(a != '.')
            {
                a = Console.ReadKey().KeyChar;
                if(a == ' ')
                {
                    probels++;
                }
            }
            Console.WriteLine("\nпробелов - {0} в предложении", probels);
            Console.WriteLine("Нажмите enter чтоб продолжить!");
            Console.ReadKey();
        }
        //--------------2 Задание-------
        public static void zadanie2()
        {
            Console.WriteLine("Введите 6-значное число!(билет)");
            char a;
            int b = 0;
            int c = 0;
            for(int i = 0; i < 6; i++)
            {
                a = Console.ReadKey().KeyChar;
                if(i < 3)
                {
                    b += (int)(a) - 48;
                }
                if (i > 2)
                {
                    c += (int)(a) - 48;
                }
            }
            if (b == c)
            {
                Console.WriteLine("\nВаш билет счастливый! {0}, {1}", b, c);
            } else
            {
                Console.WriteLine("\nВаш билет не счастливый! {0}, {1}", b, c);
            }
            Console.WriteLine("Нажмите enter чтоб продолжить!");
            Console.ReadKey();
        }
        //--------------3 Задание-------
        public static void zadanie3()
        {
            Console.Write("Введите любой символ: ");
            char c = Console.ReadKey().KeyChar;
            int b = c;
            Console.WriteLine("\nКод символа {0} - {1}", c, b);
            Console.WriteLine("Код прописной {1} - {0}", b + 32, (char)(c + 32));
            Console.WriteLine("Нажмите enter чтоб продолжить!");
            Console.ReadKey();
        }
        //--------------4 Задание-------
        public static void zadanie4()
        {
            int a, b;
            Console.WriteLine("Введите два числа - A и B(A > B) С помощью ENTER!");
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
            for (int i = a; i <= b; i++)
            {
                for(int j = 0; j < i; j++)
                {
                    Console.Write(i);
                    Console.Write(" ");
                }
                Console.Write("\n");
            }
            Console.WriteLine("Нажмите enter чтоб продолжить!");
            Console.ReadKey();
        }
        //--------------5 Задание-------
        public static void zadanie5()
        {
            char f, s, t;
            int a, b, c;
            Console.WriteLine("Введите трех-значное число (x > 0)!");
            f = Console.ReadKey().KeyChar;
            a = (int)(f) - 48;
            s = Console.ReadKey().KeyChar;
            b = (int)(s) - 48;
            t = Console.ReadKey().KeyChar;
            c = (int)(t) - 48;
            Console.WriteLine("\nВ перевернутом виде");
            Console.WriteLine("{0}{1}{2}", f, s, t);
            Console.WriteLine("Нажмите enter чтоб продолжить!");
            Console.ReadKey();
        }
    }
}
