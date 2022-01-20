#include <bits/stdc++.h>
using namespace std;

void swap(int arr[],int n, int indx1, int indx2){
    int temp = arr[indx2];
    arr[indx2] = arr[indx1];
    arr[indx1]=temp;
}

void TargetSumPair(vector<int> arr, int target){

   sort(arr.begin(), arr.end());
   int i,j; i=0; j=arr.size()-1;

   int sum=0;

   while(i<=j){
       sum = arr[i] + arr[j];

       if(sum==target) {
           cout<<arr[i]<<" "<<arr[j]<<endl;
           i++; j--;
       }
       else if(sum < target) i++;
       else if(sum > target) j--;
   }
     
}
   

int main(){

    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++){
       cin>>arr[i];
    }

    int target; cin>>target;

    TargetSumPair(arr, target);


    
}