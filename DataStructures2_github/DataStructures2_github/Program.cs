using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures2_github
{
    abstract class List<T>
    {
        public abstract T GetValue();

        public abstract List<T> Next();

        public abstract List<U> Map<U>(Func<T, U> f);

        public abstract List<U> FlatMap<U>(Func<T, List<U>> f);

        public abstract U FoldL<U>(Func<T, U, U> f, U ident);

        public abstract U FoldR<U>(Func<T, U, U> f, U ident);

        public abstract List<T> Add(T el);

        public abstract List<T> RemoveEqual(T el);

        public abstract T GetAtR(int index);

        public abstract T GetAtFL(int index);

        public abstract T GetAtFR(int index);

        public abstract List<T> RemoveAtR(int index);

        public abstract List<T> RemoveAtFL(int index);

        public abstract List<T> RemoveAtFR(int index);

        public abstract T FindFirst(Func<T, bool> f);

        public abstract List<T> Filter(Func<T, bool> f);
    }

    class EmptyList<T> : List<T>
    {
        public override T GetValue()
        {
            return default(T);
        }

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

        public override U FoldL<U>(Func<T, U, U> f, U ident)
        {
            return ident;
        }

        public override U FoldR<U>(Func<T, U, U> f, U ident)
        {
            return ident;
        }

        public override List<T> Add(T el)
        {
            return new ListNode<T>(el, new EmptyList<T>());
        }

        public override List<T> RemoveEqual(T el)
        {
            return new EmptyList<T>();
        }

        public override T GetAtR(int index)
        {
            throw new IndexOutOfRangeException();
        }

        public override T GetAtFL(int index)
        {
            throw new IndexOutOfRangeException();
        }

        public override T GetAtFR(int index)
        {
            throw new IndexOutOfRangeException();
        }

        public override List<T> RemoveAtR(int index)
        {
            return new EmptyList<T>();
        }

        public override List<T> RemoveAtFL(int index)
        {
            return new EmptyList<T>();
        }

        public override List<T> RemoveAtFR(int index)
        {
            return new EmptyList<T>();
        }

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

        public override T GetValue()
        {
            return Head;
        }

        public override List<T> Next()
        {
            return Tail;
        }

        public override List<U> Map<U>(Func<T, U> f)
        {
            return this.FoldR<List<U>>((x, y) => new ListNode<U>(f(x), y), new EmptyList<U>());
        }

        public override List<U> FlatMap<U>(Func<T, List<U>> f)
        {
            return f(Head);
        }

        public override U FoldL<U>(Func<T, U, U> f, U ident)
        {
            return Tail.FoldL(f, f(Head, ident));     //   ((ident x Head2) x Head1) x Head0
        }

        public override U FoldR<U>(Func<T, U, U> f, U ident)
        {
            return f(Head, Tail.FoldR(f, ident));     //   Head0 x (Head1 x (Head2 x ident))
        }

        public override List<T> Add(T el)
        {
            return this.FoldR<List<T>>((x, y) => new ListNode<T>(x, y), new ListNode<T>(el, new EmptyList<T>()));
        }

        public override List<T> RemoveEqual(T el)
        {
            return this.FoldR<List<T>>((x, y) =>
            {
                if (x.Equals(el))
                {
                    return new ListNode<T>(x, y);
                }
                else
                {
                    return y;
                }
            }, new EmptyList<T>());
        }

        public override T GetAtR(int index)
        {
            if (index < 0) throw new IndexOutOfRangeException();
            if (index == 0) return Head;
            else return Tail.GetAtR(index - 1);
        }

        public override T GetAtFL(int index)
        {
            var akum = this.FoldL((x, y) =>
            {
                return y.Combine(y.Current, x);
            }, new AkumGetAtFL(false, index, 0, default(T)));

            return akum.Value;
        }

        class AkumGetAtFL
        {
            public bool Found { get; set; }
            public int Index { get; set; }
            public int Current { get; set; }
            public T Value { get; set; }

            public AkumGetAtFL(bool found, int index, int current, T value)
            {
                this.Found = found;
                this.Index = index;
                this.Current = current;
                this.Value = value;
            }

            public AkumGetAtFL Combine(int current, T value)
            {
                if (Found == true)
                {
                    return new AkumGetAtFL(true, Index, Current, Value);
                }
                else if (current == Index)
                {
                    return new AkumGetAtFL(true, Index, Current, value);
                }
                else
                {
                    return new AkumGetAtFL(false, Index, Current + 1, Value);
                }
            }
        }

        public override T GetAtFR(int index)
        {
            var akum = this.FoldR((x, y) =>
            {
                return y.Combine(y.Current, x);
            }, new AkumGetAtFR(false, index, 0, default(T)));

            return akum.Value;
        }

        class AkumGetAtFR
        {
            public bool Found { get; set; }
            public int Index { get; set; }
            public int Current { get; set; }
            public T Value { get; set; }

            public AkumGetAtFR(bool found, int index, int current, T value)
            {
                this.Found = found;
                this.Index = index;
                this.Current = current;
                this.Value = value;
            }

            public AkumGetAtFR Combine(int current, T value)
            {
                if (Found == true)
                {
                    return new AkumGetAtFR(true, Index, Current, Value);
                }
                else if (current == Index)
                {
                    return new AkumGetAtFR(true, Index, Current, value);
                }
                else
                {
                    return new AkumGetAtFR(false, Index, Current + 1, Value);
                }
            }
        }

        public override List<T> RemoveAtR(int index)
        {
            if (index < 0) throw new IndexOutOfRangeException();
            if (index == 0) return Tail;
            else return new ListNode<T>(Head, Tail.RemoveAtR(index - 1));
        }

        public override List<T> RemoveAtFL(int index)
        {
            var akum = this.FoldL((x, y) =>
            {
                return y.Combine(y.Current, new ListNode<T>(x, new EmptyList<T>()));
            }, new AkumRemoveAt(false, index, 0, new EmptyList<T>()));

            return akum.Value;
        }

        public override List<T> RemoveAtFR(int index)
        {
            throw new NotImplementedException();
        }

        class AkumRemoveAt
        {
            public bool Removed { get; set; }
            public int Index { get; set; }
            public int Current { get; set; }
            public List<T> Value { get; set; }

            public AkumRemoveAt(bool removed, int index, int current, List<T> value)
            {
                this.Removed = removed;
                this.Index = index;
                this.Current = current;
                this.Value = value;
            }

            public AkumRemoveAt Combine(int current, ListNode<T> value)
            {
                if (Removed == true)
                {
                    return new AkumRemoveAt(true, Index, Current, Value.Add(value.GetValue()));
                }
                else if (current == Index)
                {
                    return new AkumRemoveAt(true, Index, Current, Value);
                }
                else
                {
                    return new AkumRemoveAt(false, Index, Current + 1, Value.Add(value.GetValue()));
                }
            }
        }

        public override T FindFirst(Func<T, bool> f)
        {
            return f(Head) ? Head : Tail.FindFirst(f);
        }

        public override List<T> Filter(Func<T, bool> f)
        {
            return this.FoldR<List<T>>((x, y) =>
            {
                if (f(x))
                {
                    return new ListNode<T>(x, y);
                }
                else
                {
                    return y;
                }
            }, new EmptyList<T>());
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

            List<int> list = new ListNode<int>(5, new ListNode<int>(6, new ListNode<int>(7, new ListNode<int>(8, new ListNode<int>(9, new EmptyList<int>())))));
            Console.Out.WriteLine(list);

            /*List<int> _MapResult = list.Map(x => x + 2);
            Console.Out.WriteLine(_MapResult);

            //List<int> _FlatMapResult = list.FlatMap(x => new ListNode<>())   ??? jak uzyc takiego FlatMap ???

            int _FoldResult = mapResult.Fold((x, y) => x * y, 1);
            Console.Out.WriteLine(_FoldResult);

            int _FindFirstResult = list.FindFirst(x => x == 2);
            Console.Out.WriteLine(_FindFirstResult);*/

            //List<int> _AddResult = list.Add(1);
            //Console.Out.WriteLine(_AddResult);

            //List<int> _RemoveResult = list.RemoveAt(1);
            //Console.Out.WriteLine(_RemoveResult);

            //List<int> _FilterResult = list.Filter(x => x % 2 == 0);
            //Console.Out.WriteLine(_FilterResult);

            //int _FoldLResult = list.FoldL((x, y) => x + y, 0);
            //Console.Out.WriteLine(_FoldLResult);

            //int _GetAtRResult = list.GetAtR(2);
            //Console.Out.WriteLine(_GetAtRResult);

            //List<int> _RemoveAtRResult = list.RemoveAtR(2);
            //Console.Out.WriteLine(_RemoveAtRResult);

            int indexRemoveAtFL = 1;
            List<int> _RemoveAtFLResult = list.RemoveAtFL(indexRemoveAtFL);
            Console.Out.WriteLine("RemoveAtFL(" + indexRemoveAtFL + ") : " + _RemoveAtFLResult);

            int indexGetAtFL = 9;
            int _GetAtFLResult = list.GetAtFL(indexGetAtFL);
            Console.Out.WriteLine("GetAtFL(" + indexGetAtFL + ") : " + _GetAtFLResult);

            //int indexGetAtFR = 1;
            //int _GetAtFRResult = list.GetAtFR(indexGetAtFR);
            //Console.Out.WriteLine("GetAtFR(" + indexGetAtFR + ") : " + _GetAtFRResult);
        }
    }
}

/* do zadan ponizej: trzeba stworzyc akumulator ktory bedzie niosl odpowiednia informacje (obiekt)
 * T GetAt(int index) 1 FoldR
 * RemoveAt  1 FoldR
 * 
 * 
 * 
 * 
 */
