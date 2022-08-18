#include<bits/stdc++.h>
using namespace std;


int main(){

     vector<int> nums={3,2,4};  int target=6;
     vector<int> result;
     unordered_map<int,int> hash;

  
    for(int i=0; i<nums.size(); i++){
        
        if(hash.find(target-nums[i]) != hash.end()){
            result.push_back(i);
            result.push_back(hash[target-nums[i]]);
            break;
        }
        
        hash[nums[i]]=i;
        
    }
          
    for(int indx : result){
        cout<<indx<<" ";
    }


 

}


