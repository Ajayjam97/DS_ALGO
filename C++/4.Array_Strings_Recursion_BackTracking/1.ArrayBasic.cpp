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

    void reverseArray(vector<int>& nums, int beg, int end){   
        while(beg<end){
            int temp = nums[beg];
            nums[beg++]=nums[end];
            nums[end--]=temp;
        }
    }
    
    void rotateArray(vector<int>& nums, int k) {
        
        k=k%nums.size();
        if(k<0) k=k+nums.size();
        
        reverseArray(nums,0,nums.size()-k-1);
        reverseArray(nums,nums.size()-k,nums.size()-1);
        reverseArray(nums,0,nums.size()-1);
    }

int main(){
        
    //    string s="the sky is blue";
    //    cout<<reverseWords(s);

    vector<int> nums = {1,2,3,4,5}; int k=2;
    rotateArray(nums,k);
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
        

}