#include <bits/stdc++.h>
using namespace std;

void CountSort(int arr[],int n, int hi){

    int fmap[hi+1];

    for(int i=0; i<n; i++){
        fmap[arr[i]]++;
    }

    int j=0;
    for(int i=0; i<(sizeof(fmap)/sizeof(int)); i++){
        while(fmap[i]--){
            arr[j]=i;
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

    int hi; cin>>hi;
    CountSort(arr, arrsize, hi);

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }
    
}