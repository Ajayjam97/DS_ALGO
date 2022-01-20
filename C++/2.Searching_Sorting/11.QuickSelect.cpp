#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int indx1, int indx2){
    int temp = arr[indx2];
    arr[indx2] = arr[indx1];
    arr[indx1]=temp;
}

int PartitionIndex(vector<int> &arr, int lo, int hi, int pivot){

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

int QuickSelect(vector<int> &arr, int lo, int hi, int k){

    
    int pivot = arr[hi];
    int pi=PartitionIndex(arr, lo, hi, pivot);

    int ans=0;

    if(pi==k) ans = pivot;
    else if(pi < k) ans =  QuickSelect(arr, pi+1, hi, k);
    else if(pi > k) ans =  QuickSelect(arr, lo, pi-1, k);

    return ans;    
     
}
   

int main(){

    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++){
       cin>>arr[i];
    }

    int k; cin>>k;

    int kthnum = QuickSelect(arr, 0, arrsize-1, k);

    cout<<kthnum<<endl;


    
}