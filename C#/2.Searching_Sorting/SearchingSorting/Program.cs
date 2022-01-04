using System;

namespace SearchingSorting
{
    class Program
    {

        public static bool LinearSearch(int[] arr, int num){

            for(int i=0; i<arr.Length; i++){
                if(arr[i]==num) return true;
            }

            return false;
        }

        public static void Searching(){

            int[] arr = {1,2,3,4,5};
            int num = 9;

            bool found = LinearSearch(arr, num);

            Console.WriteLine(string.Join(",", arr));
            Console.WriteLine("{0} found", (found)?"Yes!":"No, not");


        }

        static void Main(string[] args)
        {
            Searching();
        }
    }
}
