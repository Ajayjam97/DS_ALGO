#include <bits/stdc++.h>
using namespace std;

bool BinarySearchIterative(int arr[],int n, int num ){

    int lo=0; int hi=n-1;
    int mid;

    while(lo<hi){
        
        mid=(lo+hi)/2;
        if(arr[mid]>num){
            hi=mid-1;
        }
        else if(arr[mid]<num){
            lo=mid+1;
        }
        else{
            return true;
        }

    }

    return false;
    
    
}

bool BinarySearchRecursive(int arr[],int lo, int hi, int num ){

    if(lo>hi) return false;

    int mid = (lo+hi)/2;
 
    if(arr[mid]>num) return BinarySearchRecursive(arr,lo,mid-1,num);
    else if(arr[mid]<num) return BinarySearchRecursive(arr,mid+1,hi,num);

    if(arr[mid]==num) return true;

}

int main(){
    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }
    
    int num; cin>>num;
    cout<<(BinarySearchIterative(arr,arrsize,num)?"True":"False")<<endl;
    cout<<(BinarySearchRecursive(arr,0,arrsize-1,num)?"True":"False");
    
}