// The author of this program is Marek Küthe
// Website: mk16.de
// E-Mail: m.k@mk16.de

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace good_bad
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Hello User!";
            Console.WriteLine("Hello User! Enter a number:");

            int num = Int32.Parse(Console.ReadLine());

            if(num < 0)
            {
                Console.Title = "Crazy";
                Console.WriteLine("The number is crazy!");
            }
            else if(num % 2 == 0)
            {
                Console.Title = "Good";
                Console.WriteLine("The number is good!");
            }
            else
            {
                Console.Title = "Bad";
                Console.WriteLine("The number is bad!");
            }
        }
    }
}