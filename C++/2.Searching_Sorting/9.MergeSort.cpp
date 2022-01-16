#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int n, int indx1, int indx2){
    int temp = arr[indx2];
    arr[indx2] = arr[indx1];
    arr[indx1]=temp;
}

vector<int> Merge(vector<int> arr1, vector<int> arr2){
    int s1=arr1.size();
    int s2=arr2.size();

    int i,j,k; i=j=k=0;
    vector<int> res;

    while(i<s1 && j<s2){

        if(arr1[i]>arr2[j]){
            res.emplace_back(arr2[j]);
            j++; 
        }
        else{
            res.emplace_back(arr1[i]);
            i++;
        }
    }

    while(i<s1){
        res.emplace_back(arr1[i]);
        i++;
    }

    while(j<s2){
        res.emplace_back(arr2[j]);
        j++; 
    }

    return res;
}

vector<int> MergeSort(vector<int> arr, int lo, int hi){

    if(lo==hi){
        vector<int> res;
        res.emplace_back(arr[lo]);
        return res;
    }

    if(lo<hi){
        int mid=lo+(hi-lo)/2;
        vector<int> lefthalf = MergeSort(arr, lo, mid);
        vector<int> righthalf = MergeSort(arr, mid+1, hi);
        vector<int> res = Merge(lefthalf,righthalf);
        return res;
    }
     
}
   

int main(){

    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++){
       cin>>arr[i];
    }

    vector<int> res(arrsize);
    res = MergeSort(arr, 0, arrsize-1);

    for(int i=0; i<res.size(); i++){
       cout<<res[i]<<" ";
    }


    
}