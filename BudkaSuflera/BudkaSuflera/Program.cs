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
        public static void Main(string[] args)
        {
            CorrectCugowski();

            Console.In.ReadLine();
        }

        static void CorrectCugowski()
        {
            string original = "PA JOLKA PAMIETASZ LATO ZE SNOW";
            string attempt = "PAMIETASZ ZE SNOW";

            int counter = 0;
            int originalWordBeginning = 0;
            int attemptWordBeginning = 0;
            int j = 0;
            bool wrongWord = false;

            SortedList<string, int> missed = new SortedList<string, int>();

            for (int i = 0; i < original.Length; i++)
            {
                if (!wrongWord)
                {
                    if (original[i] == (j < attempt.Length ? attempt[j] : '.'))
                    {
                        j++;
                    }
                    else
                    {
                        //string debugString = j < attempt.Length ? attempt[j].ToString() : ".";
                        //Console.Out.WriteLine(original[i].ToString() + " - " + debugString);

                        wrongWord = true;
                        j = attemptWordBeginning;
                    }
                }
                if (original[i] == ' ' || i == original.Length - 1)
                {
                    if (wrongWord)
                    {
                        int wordLength = i - originalWordBeginning;
                        if (i == original.Length - 1)
                        {
                            wordLength++;
                        }

                        string wordToAdd = original.Substring(originalWordBeginning, wordLength);
                        if (missed.ContainsKey(wordToAdd))
                        {
                            missed[wordToAdd]++;
                        }
                        else
                        {
                            missed.Add(wordToAdd, 1);
                        }
                        counter++;

                        wrongWord = false;
                    }
                    else if (attempt[j] == ' ')
                    {
                        j++;
                        attemptWordBeginning = j;
                    }

                    originalWordBeginning = i + 1;
                }
            }

            Console.Out.WriteLine(counter);
            foreach (KeyValuePair<string, int> pair in missed)
            {
                for (int i = 0; i < pair.Value; i++)
                {
                    Console.Out.WriteLine(pair.Key);
                }
            }
        }





        static void CorrectCugowskiOld()
        {
            string input0 = "JOLKA JOLKA PAMIETASZ LATO ZE SNOW";
            string input1 = "PAMIETASZ ZE SNOW";

            Dictionary<string, int> originalDict = GetDictionaryFromString(input0);
            Dictionary<string, int> attemptDict = GetDictionaryFromString(input1);

            List<string> differenceList = new List<string>();

            foreach (KeyValuePair<string, int> orPair in originalDict)
            {
                if (!attemptDict.ContainsKey(orPair.Key) || attemptDict[orPair.Key] != orPair.Value)
                {
                    int numberOfOccurencies = attemptDict.ContainsKey(orPair.Key) ? orPair.Value - attemptDict[orPair.Key] : orPair.Value;
                    for (int i = 0; i < numberOfOccurencies; i++)
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




        static void DamianVsCugowski()
        {
            Tuple<Dictionary<string, int>, int> originalInput = GetDictionaryAndCountFromString(
                Console.In.ReadLine()
            );

            Tuple<Dictionary<string, int>, int> attemptInput = GetDictionaryAndCountFromString(
                Console.In.ReadLine()
            );

            Dictionary<string, int> originalDict = originalInput.Item1;
            Dictionary<string, int> attemptDict = attemptInput.Item1;
            foreach (KeyValuePair<string, int> pair in attemptDict)
            {
                int count = originalDict[pair.Key];
                int missingWords = count - pair.Value;
                originalDict[pair.Key] = missingWords;
            }

            SortedList<string, int> result = new SortedList<string, int>(originalDict.Count);
            foreach (KeyValuePair<string, int> pair in originalDict)
            {
                result[pair.Key] = pair.Value;
            }

            Console.Out.WriteLine(originalInput.Item2 - attemptInput.Item2);
            foreach (KeyValuePair<string, int> pair in result)
            {
                for (int i = 0; i < pair.Value; i++)
                {
                    Console.Out.WriteLine(pair.Key);
                }
            }
        }
        static Tuple<Dictionary<string, int>, int> GetDictionaryAndCountFromString(string s)
        {
            Dictionary<string, int> dict = new Dictionary<string, int>();
            int count = 0;
            foreach (string word in s.Split(' '))
            {
                count++;
                int value;
                int presentOnList = dict.TryGetValue(word, out value) ? value + 1 : 1;
                dict[word] = presentOnList;
            }
            return Tuple.Create(dict, count);
        }
    }
}