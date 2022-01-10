#include <bits/stdc++.h>
using namespace std;

void CountSort(int arr[],int n, int hi){

    int fmap[hi+1];
    memset(fmap, 0, sizeof(fmap));

    for(int i=0; i<n; i++){
        int index=arr[i];
        fmap[index]++;
    }

    int j=0;
    for(int i=0; i<(sizeof(fmap)/sizeof(int)); i++){
        while(fmap[i]--){
            arr[j]=i;
            j++;
        }
    }
       
}

void RangeCountSort(int arr[],int n, int hi, int lo){

    int fmap[hi-lo+1];
    memset(fmap, 0, sizeof(fmap));

    for(int i=0; i<n; i++){
        int index=arr[i];
        fmap[index-lo]++;
    }

    int j=0;
    for(int i=0; i<(sizeof(fmap)/sizeof(int)); i++){
        while(fmap[i]--){
            arr[j]=i+lo;
            j++;
        }
    }

}


//Provides stable sort
void CountSortUsingPrefixSum(int arr[],int n, int hi, int lo){

    int fmap[hi-lo+1];
    memset(fmap, 0, sizeof(fmap));

    //1.Generate frequency map
    for(int i=0; i<n; i++){
        int index=arr[i];
        fmap[index-lo]++;
    }

    //2.Generate generic prefixsum array
    fmap[0]--;
    for(int i=1; i<n; i++){
        fmap[i]+=fmap[i-1];
    }

    //3.Add elements in a new array from back. Also decrease the count of fmap[i] after every iteration.
    int narr[n];
    for(int i=n-1; i>=0; i--){
        narr[fmap[arr[i]-lo]] = arr[i];
        fmap[arr[i]-lo]--;
    }

    for(int i=0; i<n; i++){
        arr[i]=narr[i];
    }

} 
   

int main(){

    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }

    int lo,hi; cin>>lo>>hi;
    //CountSort(arr, arrsize, hi);
    //RangeCountSort(arr, arrsize, hi, lo);
    CountSortUsingPrefixSum(arr, arrsize, hi, lo);


    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }

    
}