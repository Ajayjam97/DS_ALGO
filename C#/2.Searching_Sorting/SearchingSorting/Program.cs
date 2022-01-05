using System;

namespace SearchingSorting
{
    class Program
    {

        public static int BinarySearch(int[] arr,int lo, int hi, int num){

            int mid=(lo+(hi-lo)/2);

            if(arr[mid]==num) return mid;
            if(arr[mid]>num) return BinarySearch(arr, 0, mid-1,num);
            if(arr[mid]<num) return BinarySearch(arr, mid+1, hi,num);

            return -1;
        }

        public static void Searching(){

            int[] arr = {1,2,3,4,5,6,7,8,9,10};
            int num = 9;

            // bool found = LinearSearch(arr, num);
            // Console.WriteLine(string.Join(",", arr));
            // Console.WriteLine("{0} found", (found)?"Yes!":"No, not");

            int index = BinarySearch(arr, 0, arr.Length-1,num);
            Console.WriteLine(string.Join(",", arr));
            if (index!=-1) Console.WriteLine("{0} found at index: {1}", num, index);
            else           Console.WriteLine("Not Found!");


        }

        static void Main(string[] args)
        {
            Searching();
        }
    }
}
