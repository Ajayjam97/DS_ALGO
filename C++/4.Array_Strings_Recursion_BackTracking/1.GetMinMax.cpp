#include <bits/stdc++.h>
using namespace std;

struct Pair{
    long long int min;
    long long int max;
};

struct Pair getMinMax(long long int arr[], long long int n) {
    
    struct Pair minmax;
    
    minmax.min=arr[0];
    minmax.max=arr[0];
    
    for(int i=0; i<n; i++){
        
        if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }
        
        if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }
    }
    
    return minmax;
    
}

string reverseWord(string str){
    
  //Your code here
  int start=0;
  int end=str.size()-1;

  while(start<end){
      int temp=str[start];
      str[start++]=str[end];
      str[end--]=temp;
  }

  return str;
}


int main(){

}