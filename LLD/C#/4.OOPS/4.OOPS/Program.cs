using System;

namespace _4.OOPS
{
    class Program
    {
        public class Student{

            public int age;
            public string name;

            public void AnnounceYourSelf(){
                Console.WriteLine("Age of {0} is {1}.",this.name,this.age); 
            }
        } 

        public static void Swap(Student S1, Student S2){
            Student temp=S1;
            S1=S2;
            S2=temp;
        }

        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            Student S1 = new Student();
            S1.age=10;  S1.name="A";
            S1.AnnounceYourSelf();

            Student S2 = new Student();
            S2.age=20;  S2.name="B";
            S2.AnnounceYourSelf();

            Student S3 = S2;
            S3.age=30;  S3.name="C";
            S3.AnnounceYourSelf();
            S2.AnnounceYourSelf();

            Console.WriteLine("Checking for swap between 2 student objects");

            S1.AnnounceYourSelf();
            S2.AnnounceYourSelf();
            Swap(S1, S2);
            S1.AnnounceYourSelf();
            S2.AnnounceYourSelf();

            
        }
    }
}
