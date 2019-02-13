using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures2_github
{
    abstract class List<T, U> // jesli Fold ma przyjac funkcje o dwoch parametrach to List musi byc o dwoch parametrach
    {
        public abstract List<T, U> Next();

        public abstract List<T, T> Map(Func<T, T> f);

        public abstract U Fold(Func<T, U, U> f, U ident); // tak sobie wyobrazam sygnature
    }

    class EmptyList<T, U> : List<T, U> // wszedzie gdzie sie nie kompilowalo dodalem drugi parametr
    {
        public override List<T, U> Next()
        {
            return null;
        }

        public override List<T, T> Map(Func<T, T> f)
        {
            return new EmptyList<T, T>();
        }

        public override U Fold(Func<T, U, U> f, U ident)
        {
            return ident;
        }

        public override string ToString()
        {
            return String.Empty;
        }
    }

    class ListNode<T, U> : List<T, U>
    {
        public T Head { get; }
        public List<T, U> Tail { get; }

        public ListNode(T head, List<T, U> tail)
        {
            this.Head = head;
            this.Tail = tail;
        }

        public override List<T, U> Next()
        {
            return Tail;
        }

        public override List<T, T> Map(Func<T, T> f)
        {
            //return new ListNode<T, U>(f(Head), Tail.Map(f));   to jest stara metoda Map

            // i tutaj najwazniejsze, proba zrobienia Map przez Fold. Wydaje mi sie ze jest dosyc dobrze ale nie wiem co wstawic jako Tail nowego ListNode
            // chociaz caly czas nie podoba mi sie to ze List<T,U>.Map(f) zwraca List<T,T> czyli obiekt o innych typach generycznych.
            return this.Fold((x, y) => new ListNode<T, T>(f(x), y), new EmptyList<T, U>().Map(f));
        }

        public override U Fold(Func<T, U, U> f, U ident)
        {
            //return f(ident, Tail.Fold(f, Head));   to jest FoldRight

            return f(Head, Tail.Fold(f, ident));
        }

        public override string ToString()
        {
            return Head.ToString() + Tail.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Lesson1();

            Console.In.ReadLine();
        }

        static void Lesson1()
        {
            // no i tutaj, kombinowalem zeby ten Fold przyjmowal funkcje o dwoch parametrach ale co wtedy ma zwracac?

            List<int, List<int, int>> list = new ListNode<int, List<int, int>>(0, new ListNode<int, List<int, int>>(1,
                new ListNode<int, List<int, int>>(2, new ListNode<int, List<int, int>>(3, new ListNode<int, List<int, int>>(4,
                new EmptyList<int, List<int, int>>())))));
            Console.Out.WriteLine(list);

            //List<int, int> mapResult = list.Map(x => x + 1);
            //Console.Out.WriteLine(mapResult);

            List<int, int> foldResult = list.Fold((x, y) => new ListNode<int, int>(x + 1, y), new EmptyList<int, int>());
            Console.Out.WriteLine(foldResult);
        }
    }
}

