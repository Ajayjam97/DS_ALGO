using System;

namespace _2.LexicalConventions
{
    class Program
    {
        public readonly int var1 = 10;
        public const int var2 = 10;

        public Program(int var1, int var2){
            this.var1 = var1;
            //this.var2 = var2;

            Console.WriteLine("Var1: {0}", this.var1);
            //Console.WriteLine("Var2: {0}", this.var2);
        }


        public static void RefGetId(ref int id){
            id++;
        }

        public static void OutGetId(int id, out int result){
            result=id+1;
        }

        static void Main(string[] args)
        {

            //A C# program is a collection of classes.
            //A class is defined by a set of object ,variable and methods.A c# program is basically collection of tokens.
            
            //79 Keywords are there in C#
            //abstract    as
            //base        bool            break            byte
            //case        catch           char             checked            class            const            continue
            //decimal     default         delegate         do                 double
            //else        enum            event            explicit           extern
            //false       finally         fixed            float              for              foreach
            //goto
            //if          implicit        in               int                interface        internal         is
            //lock        long
            //namespace   new             null
            //object      operator        out              override
            //params      private         protected        public
            //readonly    ref             return
            //sbyte       sealed          short        sizeof     stackalloc      static       string       struct       switch
            //this        throw           true         try        typeof
            //uint        ulong           unchecked    unsafe     ushort          using
            //virtual     void            volatile
            //while


            //Difference between ref & out

            //int id=0;
            //RefGetId(ref id);
            //Console.WriteLine(id);

            //int result=0;
            //OutGetId(id, out result);
            //Console.WriteLine(result);



            //Difference between Const VS ReadOnly

            Program P = new Program(20, 20);

        }
    }
}
