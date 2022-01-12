#include <bits/stdc++.h>
using namespace std;

void RadixCountSort(vector<int> &arr, int lo, int hi, int exp){

    int freqmap[hi-lo+1];
    memset(freqmap, 0, sizeof(freqmap));

    for(int i=0; i<arr.size(); i++){
        int index = (arr[i]/exp)%10;
        freqmap[index]++;
    }

    freqmap[0]--;
    for(int i=1; i<(sizeof(freqmap)/sizeof(int)); i++){
        freqmap[i]+=freqmap[i-1];
    }

    int narr[arr.size()];

    for(int i=(arr.size()-1); i>=0; i--){
        int value = (arr[i]/exp)%10;
        int index = freqmap[value]--;
        narr[index] = arr[i];
    }

    for(int i=0; i<arr.size(); i++){
        arr[i] = narr[i];
    }
}


void RadixSort(vector<int> &arr, int size){

int exp=1;
while(exp<=*max_element(arr.begin(), arr.end())){
    RadixCountSort(arr, 0, 9, exp);
    exp*=10;
}

}
   

int main(){

    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arrsize; i++){
        cin>>arr[i];
    }

    RadixSort(arr, arrsize);

    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<" ";
    }

    
}