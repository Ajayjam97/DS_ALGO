using System;
using System.Linq;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace ConsoleApp1
{

    class Program
    { 

        class Hero
        {
            public int i;
            public string a;

            public Hero(int i,string a)
            {
                this.i = i;
                this.a = a;
            }

            public Hero(Hero H)
            {
                this.i = H.i;
                this.a = H.a;
            }

            public void Print()
            {
                Console.Write("["+this.i+", ");
                Console.WriteLine(this.a+"]");
            }
        }
        static void Main(string[] args)
        {
            Hero R=new Hero(10,"Ajay");
            //Hero S=new Hero(R);   //Deep Copy
            Hero S = R; //Shallow Copy
            R.Print();
            S.Print();
            R.a = "Pandit";
            R.Print();
            S.Print();
            Console.ReadLine();
        }
    }

   
}
