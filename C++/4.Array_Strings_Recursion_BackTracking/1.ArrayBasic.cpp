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

void reverseString(vector<char>& s) {
        
        int l = 0;
        int r = s.size()-1;
        
        while(l<r){
            char temp;
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            
            l++; r--;
        }
    }

vector<string> printVertically(string s) {
        
        vector<string> temp;
        istringstream sentence(s);
        string word;

        while(sentence >> word){
            temp.push_back(word);
        }    

        return temp;
        
    }


int main(){
        
        string s = "HOW ARE YOU";
        vector<string> result = printVertically(s);

        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
        

}