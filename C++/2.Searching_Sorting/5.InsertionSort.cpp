#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i , int minindex){
    int temp = arr[i];
    arr[i] = arr[minindex];
    arr[minindex] = temp;
}

void InsertionSort(int arr[],int n){

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(arr, j, j-1);
            }
        }
    }       
       
}

int main(){
    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }

    InsertionSort(arr, arrsize);

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }
    
}