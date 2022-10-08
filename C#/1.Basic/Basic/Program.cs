using System;

namespace Basic
{

    class Program
    {

        public struct Person{
            //Fields
            public string name;
            public int id;

            //Constructor
            public Person(string _name, int _id){
                name=_name; id=_id;
            }

            //Properties
            public int Id {
            get { return id; }
            set { id = value; }
            }
        }

        public enum Shapes
        {
            Circle,
            Square
        }


        static void Main(string[] args)
        {
            Console.WriteLine("HELLO WORLD C#");

            //In .Net CTS (Common Type System) defines the datatypes to be used. Broadly we have 2 types of datatypes:
            //Value type & Reference type

            //Built in value types
            //byte, sbyte, short, ushort, int, uint, long, ulong, float, double, decimal, char, bool
            sbyte sb=-8; byte b=8; short shrt=-16; ushort us=16; int i=-32; uint ui=32; long l=-64; ulong ul=64; 
            float f=3.38843884f; //float 6-digit precision
            double dbl=8.388438843884388438843884d;  //double 18-digit precision
            decimal dec=8.388438843884388438843884388438843884m;  //decimal 28-digit precision
            char c='A'; bool bl=true; 
            Console.WriteLine("{0}| {1}| {2}| {3}| {4}| {5}| {6}| {7}| {8}| {9}| {10}| {11}| {12}|", sb, b, shrt, us, i, ui, l, ul, f, dbl, dec, c, bl);
            Console.WriteLine("{0}| {1}| {2}| {3}| {4}| {5}| {6}| {7}| {8}| {9}| {10}|", sbyte.MaxValue, byte.MaxValue, short.MaxValue, ushort.MaxValue, Int32.MaxValue, uint.MaxValue, long.MaxValue, ulong.MaxValue, float.MaxValue, double.MaxValue, decimal.MaxValue);

            //User defined value types
            //struct, enum
            Person p = new Person("Ajay", 103);
            Console.WriteLine("{0} : {1}",p.Id, p.name);

            Shapes s = Shapes.Circle;
            Console.WriteLine("{0}, {1}",s, Shapes.Square);



            //Built in reference types
            //object, string, array

            //User defined reference types
            //class, interface, delegate
            

            


        }
    }
}
