#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int n){

    for(int i=0; i<n; i++){
        for(int j=1; j<(n-i); j++){
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
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

    BubbleSort(arr, arrsize);

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }
    
}