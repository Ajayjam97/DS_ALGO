#include <bits/stdc++.h>
using namespace std;  

void PrintPermutation(string s,string output){

    if(s.size()<1){
        cout<<output<<endl;
        return;
    }

    for(int i=0; i<s.size(); i++){
        PrintPermutation(s.substr(0,i)+s.substr(i+1, s.size()-1), output+s[i]);
    }

}

int main(){

    PrintPermutation("ABC", "");

}