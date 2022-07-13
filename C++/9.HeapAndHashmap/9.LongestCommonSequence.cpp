#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
  
using namespace std;

int main(){

    unordered_map<int, bool> mymap;
    int n;

    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }

    //1. Make a hashmap of presence

    for(int key : arr){
        mymap[key] = true;
    }

    //2. Make starting point of the sequence

    for(int key : arr){
        if(mymap.find(key-1)!=mymap.end())
        mymap[key] = false;
    }

    //3. Get length & starting point of the sequence

    int maxlength = 0;
    int starting = 0;

    for(int key : arr){

        if(mymap[key] == true){
         
            int len = 1;
            int st = key;

            while(mymap.find(key+1) != mymap.end()){
                len++;
                key++;
            }

            if(maxlength < len){
                maxlength = len;
                starting = st;
            }

            mymap[key] = false;

        }
    }


    //4. Print answer
    for(int i=0; i < maxlength; i++){
    cout<<starting<<endl;   starting++;
    }

    return 0;
}


