using System;

namespace SearchingSorting
{
    class Program
    {

        public static void CountSort(int[] arr,int lo, int hi){

            int[] freqmap=new int[hi-lo+1];

            //1.Generate frequency map
            for(int i=0; i<arr.Length; i++){
                int index = arr[i]-lo;     
                freqmap[index]++;
            }
    
            freqmap[0]--; 
            //2.Generate prefix sum from freqmap
            for(int i=1; i<freqmap.Length; i++){
                freqmap[i]+=freqmap[i-1];
            }

            int[] narr=new int[arr.Length];
            //3.Traverse the array from back and fill the values in their respective last index using 
            for(int i=arr.Length-1; i>=0; i--){
                int value = arr[i];
                int index = arr[i] - lo;
                int lastindex = freqmap[index];
                narr[lastindex] = value;
                freqmap[index]--;
            }

            //4.Copy newarr to arr array
            for(int i=0; i<arr.Length; i++){
                arr[i] = narr[i];
            }
         }

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

        public static void Sorting(){
            
            int[] arr = {3,7,6,2,8,9,4,5,7,6,5,3};

            Console.WriteLine(string.Join(",", arr));
            CountSort(arr,2,9);
            Console.WriteLine(string.Join(",", arr));

        }

        static void Main(string[] args)
        {
            //Searching();
            Sorting();
        }
    }
}
