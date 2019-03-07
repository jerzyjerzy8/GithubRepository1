using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures2_github
{
    abstract class List<T>
    {
        public abstract List<T> Next();

        public abstract List<U> Map<U>(Func<T, U> f);

        public abstract List<U> FlatMap<U>(Func<T, List<U>> f);

        public abstract U Fold<U>(Func<T, U, U> f, U ident);

        public abstract void Add(T el);

        public abstract void RemoveAt(int index);

        public abstract T FindFirst(Func<T, bool> f);

        public abstract List<T> Filter(Func<T, bool> f);
    }

    class EmptyList<T> : List<T>
    {
        public override List<T> Next()
        {
            return null;
        }

        public override List<U> Map<U>(Func<T, U> f)
        {
            return new EmptyList<U>();
        }

        public override List<U> FlatMap<U>(Func<T, List<U>> f)
        {
            return new EmptyList<U>();
        }

        public override U Fold<U>(Func<T, U, U> f, U ident)
        {
            return ident;
        }

        public override void Add(T el) { }   // ??? potrzebowalbym zmienic przypisanie z EmptyList na new ListNode<T>(el, new EmptyList<T>()) ale jak ???

        public override void RemoveAt(int index) { }

        public override T FindFirst(Func<T, bool> f)
        {
            return default(T);
        }

        public override List<T> Filter(Func<T, bool> f)
        {
            return new EmptyList<T>();
        }

        public override string ToString()
        {
            return String.Empty;
        }
    }

    class ListNode<T> : List<T>
    {
        public T Head { get; private set; }
        public List<T> Tail { get; }

        public ListNode(T head, List<T> tail)
        {
            this.Head = head;
            this.Tail = tail;
        }

        public override List<T> Next()
        {
            return Tail;
        }

        public override List<U> Map<U>(Func<T, U> f)
        {
            //return new ListNode<U>(f(Head), Tail.Map(f));

            return this.Fold<List<U>>((x, y) => new ListNode<U>(f(x), y), new EmptyList<U>());
            //return this.Fold((x, y) => new ListNode<T>(f(x), y), new EmptyList<U>().Map(f));
        }

        public override List<U> FlatMap<U>(Func<T, List<U>> f)
        {
            return f(Head);
        }

        public override U Fold<U>(Func<T, U, U> f, U ident)
        {
            //return f(ident, Tail.Fold(f, Head));   to jest FoldRight

            return f(Head, Tail.Fold(f, ident));
        }

        public override void Add(T el)
        {
            Tail.Add(el);
        }

        public override void RemoveAt(int index)
        {
            if (index == 0)
            {
                // ??? znowu jak zrobic this = this.Tail ???
            }
            else
            {
                Tail.RemoveAt(index - 1);
            }
        }

        public override T FindFirst(Func<T, bool> f)
        {
            return f(Head) ? Head : Tail.FindFirst(f);
        }

        public override List<T> Filter(Func<T, bool> f)
        {
            /*List<T> filtered;
            if (f(Head))
            {
                
            }*/
            return new ListNode<T>(Head, Tail);
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

            List<int> list = new ListNode<int>(0, new ListNode<int>(1, new ListNode<int>(2, new ListNode<int>(3, new ListNode<int>(4, new EmptyList<int>())))));
            Console.Out.WriteLine(list);

            List<int> mapResult = list.Map(x => x + 2);
            Console.Out.WriteLine(mapResult);

            //List<int> flatMapResult = list.FlatMap(x => new ListNode<>())   ??? jak uzyc takiego FlatMap ???

            int foldResult = mapResult.Fold((x, y) => x * y, 1);
            Console.Out.WriteLine(foldResult);

            int findFirstResult = list.FindFirst(x => x == 2);
            Console.Out.WriteLine(findFirstResult);
        }
    }
}

