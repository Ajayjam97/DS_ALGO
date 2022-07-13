#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
  
using namespace std;

int main(){

    unordered_map<int, int> mymap;
    int n1, n2;

    cin>>n1;
    vector<int> arr1(n1);

    for(int i=0; i<n1; i++)
    cin>>arr1[i];


    cin>>n2;
    vector<int> arr2(n2);

    for(int i=0; i<n2; i++)
    cin>>arr2[i];


    for(int key : arr1){
        if(mymap[key]==0){
            mymap[key] = 1;
        }
        else{
            mymap[key]++;
        }
    }

    for(int key : arr2){
        if(mymap[key]!=0){
            cout<<key<<endl;
            mymap[key]--;
        }
    }


    return 0;
}
