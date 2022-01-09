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
        
   

int main(){

    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }

    int lo,hi; cin>>lo>>hi;
    //CountSort(arr, arrsize, hi);
    RangeCountSort(arr, arrsize, hi, lo);

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }

    
}