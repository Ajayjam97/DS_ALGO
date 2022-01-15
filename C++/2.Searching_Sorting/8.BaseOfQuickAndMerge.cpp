#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int n, int indx1, int indx2){
    int temp = arr[indx2];
    arr[indx2] = arr[indx1];
    arr[indx1]=temp;
}

void Segregate01(int arr[],int n){

    int i,j;
    i=j=0;

    while(i<n){

        if(arr[i]==0){
            swap(arr,n,i,j);
            i++; j++;
        }
        else{
            i++;
        }
    }
}

void SegregateOddEven(int arr[],int n){
    int i,j;
    i=j=0;

    while(i<n){

        if((arr[i]%2)==0){   
            swap(arr,n,i,j);
            i++; j++;
        }
        else{     
            i++;
        }
    }

} 
   

int main(){

    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
       cin>>arr[i];
    }

    //Sort 01
    //Segregate01(arr, arrsize);

    //Sort array by parity
    SegregateOddEven(arr, arrsize);


    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cout<<arr[i]<<" ";
    }

    
}