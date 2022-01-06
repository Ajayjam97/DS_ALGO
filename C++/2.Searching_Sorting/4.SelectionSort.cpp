#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i , int minindex){
    int temp = arr[i];
    arr[i] = arr[minindex];
    arr[minindex] = temp;
}

void SelectionSort(int arr[],int n){

    for(int i=0; i<n; i++){
        int minindex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr, i , minindex);
    }
    
}

int main(){
    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }

    SelectionSort(arr, arrsize);

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }
    
}