using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace BudkaSuflera
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.Out.WriteLine(IsSpace(' '));

            CorrectCugowski("1 2 3\n-1 -1 -2 -3 -4");

            Console.In.ReadLine();
        }

        static void CorrectCugowski(string input)
        {
            string[] inputArr = input.Split('\n');

            HashSet<string> originalSet = new HashSet<string>();
            HashSet<string> attemptSet = new HashSet<string>();

            foreach (string el in inputArr[0].Split(' '))
            {
                originalSet.Add(el);
            }
            foreach (string el in inputArr[1].Split(' '))
            {
                attemptSet.Add(el);
            }

            foreach (string el in originalSet)
            {
                Console.Out.WriteLine(el);
            }
            Console.Out.WriteLine();
            foreach (string el in attemptSet)
            {
                Console.Out.WriteLine(el);
            }
        }

        static bool IsSpace(char ch)
        {
            return new Regex(@"^ $").IsMatch(ch.ToString());
        }
    }
}
