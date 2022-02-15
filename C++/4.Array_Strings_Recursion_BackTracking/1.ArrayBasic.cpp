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

    bool IsNotLetter(char c){

        return ((c>='a')&&(c<='z')&&(c>='A')&&(c<='Z'));
    }

vector<string> printVertically(string s) {
        
        vector<string> temp;
        istringstream sentence(s);
        string word;
        int MaxWordSize = 0;

        while(sentence >> word){
            if(word.size()>MaxWordSize) 
            MaxWordSize = word.size();
            temp.push_back(word);
        }    

        vector<string> verticalres(MaxWordSize, "");

        for(int i=0; i<temp.size(); i++){
            for(int j=0; j<MaxWordSize; j++){
                if(verticalres[j].size()>0){
                    if((j>=temp[i].size())&&(IsNotLetter(verticalres[j][verticalres[j].size()-1])))
                    verticalres[j]+=" ";
                    else
                    verticalres[j]+=(temp[i])[j];
                }
                else{
                    verticalres[j]+=(temp[i])[j];
                }

            }
        }

        return verticalres;


        
    }


int main(){
        
        string s = "TO BE OR NOT TO BE";//"HOW ARE YOU";
        vector<string> result = printVertically(s);

        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
        

}