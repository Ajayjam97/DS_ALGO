#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str){
    
    int l=0; int r=str.size()-1;
    
    while(l<r){
        char temp=str[l];
        str[l]=str[r];
        str[r]=temp;
        l++; r--;
    }
    
    return str;
 
}