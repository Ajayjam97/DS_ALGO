#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(int arr[],int n, int num ){

    for(int i=0; i<n; i++){
        if(arr[i]==num)
        return true;
    }

    return false;
}

int main(){
    int arrsize; cin>>arrsize;
    int arr[arrsize];

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
        cin>>arr[i];
    }
    
    int num; cin>>num;
    cout<<(LinearSearch(arr,arrsize,num)?"True":"False");
    
}