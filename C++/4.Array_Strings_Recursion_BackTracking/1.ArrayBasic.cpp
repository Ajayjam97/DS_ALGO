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

    string reverseWords(string s) {
        
        istringstream sentence(s);
        vector<string> words;
        string word;

        while(getline(sentence, word, ' ')){
            if(word!=" "&&word.size()!=0)
            words.push_back(word);
        }

        reverse(words.begin(), words.end());
        string reverse="";

        for(int i=0; i<words.size(); i++){
            if(i==words.size()-1)
            reverse += (words[i]);
            else
            reverse += (words[i]+" ");
        }

        return reverse;
        
    }



int main(){
        
       string s="the sky is blue";
       cout<<reverseWords(s);
        

}