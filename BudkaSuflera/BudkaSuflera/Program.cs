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

            CorrectCugowski("JOLKA JOLKA PAMIETASZ LATO ZE SNOW\nJOLKA ZE SNOW");

            Console.In.ReadLine();
        }


        static void CorrectCugowski(string input)
        {
            string[] inputArr = input.Split('\n');

            Dictionary<string, int> originalDict = GetDictionaryFromString(inputArr[0]);
            Dictionary<string, int> attemptDict = GetDictionaryFromString(inputArr[1]);

            List<string> differenceList = new List<string>();

            foreach (KeyValuePair<string, int> orPair in originalDict)
            {
                if (!attemptDict.ContainsKey(orPair.Key) || attemptDict[orPair.Key] != orPair.Value)
                {
                    int numberOfWords = attemptDict.ContainsKey(orPair.Key)? orPair.Value - attemptDict[orPair.Key] : orPair.Value;
                    for (int i = 0; i < numberOfWords; i++)
                    {
                        differenceList.Add(orPair.Key);
                    }
                }
            }

            differenceList.Sort();

            Console.Out.WriteLine(differenceList.Count);

            foreach (string el in differenceList)
            {
                Console.Out.WriteLine(el);
            }

        }


        static Dictionary<string, int> GetDictionaryFromString(string s)
        {
            Dictionary<string, int> dict = new Dictionary<string, int>();

            foreach (string word in s.Split(' '))
            {
                if (!dict.ContainsKey(word))
                {
                    dict.Add(word, 1);
                }
                else
                {
                    dict[word] += 1;
                }
            }

            return dict;
        }


        static bool IsSpace(char ch)
        {
            return new Regex(@"^ $").IsMatch(ch.ToString());
        }
    }
}
