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


int* Merge(int arr1[], int arrsize1,int arr2[],int arrsize2){

    int arrsize3 = (arrsize1+arrsize2);
    int* arr3 = new int[arrsize3];

    int i,j,k;    i=j=k=0;

    while(i<arrsize1&&j<arrsize2){
        if(arr1[i]>arr2[j]){
            arr3[k++]=arr2[j++];
        }
        else{
            arr3[k++]=arr1[i++];
        }
    }

    while(i<arrsize1){
        arr3[k++]=arr1[i++];
    }

    while(j<arrsize2){
        arr3[k++]=arr2[j++];
    }

    return arr3;
     
}
   

int main(){

    int arrsize1; cin>>arrsize1;
    int arr1[arrsize1];

    for(int i=0; i<(sizeof(arr1)/sizeof(int)); i++){
       cin>>arr1[i];
    }

    //Sort 01
    //Segregate01(arr1, arrsize1);

    //Sort array by parity
    //SegregateOddEven(arr1, arrsize1);

    // for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
    //     cout<<arr[i]<<" ";
    // }

    int arrsize2; cin>>arrsize2;
    int arr2[arrsize2];

    for(int i=0; i<(sizeof(arr2)/sizeof(int)); i++){
       cin>>arr2[i];
    }

    int arrsize3 = (arrsize1+arrsize2);
    int* arr3 = new int[arrsize3];

    //Merge two sorted arrays
    arr3 = Merge(arr1, arrsize1, arr2, arrsize2);


    for(int i=0; i<(arrsize3); i++){
        cout<<arr3[i]<<" ";
    }

    
}