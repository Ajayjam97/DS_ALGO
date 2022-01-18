#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> arr, int indx1, int indx2){
    int temp = arr[indx2];
    arr[indx2] = arr[indx1];
    arr[indx1]=temp;
}

int PartitionIndex(vector<int> arr, int lo, int hi, int pivot){

    int i,j; i=j=lo;

    while(i<=hi){
        if(arr[i]>pivot){
            i++;
        }
        else{
            swap(arr, i,j);
            i++;
            j++;
        }
    }

    return j-1;
    
}

void QuickSort(vector<int> arr, int lo, int hi, int pivot){

    if(lo>=hi) return;

    int pi=PartitionIndex(arr, lo, hi, pivot);
    QuickSort(arr, lo, pi-1, arr[pi-1]);
    QuickSort(arr, pi+1, hi, arr[hi]);
     
}
   

int main(){

    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++){
       cin>>arr[i];
    }

    vector<int> res(arrsize);
    QuickSort(arr, 0, arrsize-1, arr[arrsize-1]);

    for(int i=0; i<res.size(); i++){
       cout<<res[i]<<" ";
    }


    
}