using System;

namespace _4.OOPS
{
    class Program
    {
        public class Student{

            //Data members
            private string name;
            private int rollno;
            
            //Function members
            public void setdata(string name, int rollno){
                this.name=name;     this.rollno = rollno;
            }

            public int getrollnodata(){
                return this.rollno;
            }

            public string getnamedata(){
                return this.name;
            }

        } 


        public static void Swap1(Student S1, Student S2){
            Student temp=S1;
            S1=S2;
            S2=temp;
        }

         public static void Swap2(Student S1, Student S2){
            
            Student temp = new Student();
            temp.setdata(S1.getnamedata(), S1.getrollnodata());
            S1.setdata(S2.getnamedata(), S2.getrollnodata());
            S2.setdata(temp.getnamedata(), temp.getrollnodata());
        }

        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            Student S1 = new Student();
            S1.setdata("A",1);
            Console.WriteLine("S1 has Roll No. {0}: {1}",S1.getrollnodata(),S1.getnamedata());

            Student S2 = new Student();
            S2.setdata("B",2);
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());

            Console.WriteLine("--------After assigning refernece of S2 to a new S3 student object--------");

            Student S3 = S2;
            S3.setdata("C",3);
            Console.WriteLine("S3 has Roll No. {0}: {1}",S3.getrollnodata(),S3.getnamedata());
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());


            Console.WriteLine("--------Checking for swap between 2 student objects using 1st method--------");
            Console.WriteLine("S1 has Roll No. {0}: {1}",S1.getrollnodata(),S1.getnamedata());
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());
            Swap1(S1,S2);
            Console.WriteLine("S1 has Roll No. {0}: {1}",S1.getrollnodata(),S1.getnamedata());
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());


            Console.WriteLine("--------Checking for swap between 2 student objects using 2nd method--------");
            Console.WriteLine("S1 has Roll No. {0}: {1}",S1.getrollnodata(),S1.getnamedata());
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());
            Swap2(S1,S2);
            Console.WriteLine("S1 has Roll No. {0}: {1}",S1.getrollnodata(),S1.getnamedata());
            Console.WriteLine("S2 has Roll No. {0}: {1}",S2.getrollnodata(),S2.getnamedata());
            
        }
    }
}
