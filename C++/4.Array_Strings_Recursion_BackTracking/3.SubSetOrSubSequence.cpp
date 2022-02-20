#include <bits/stdc++.h>
using namespace std;   
   
    vector<string> getSubSequence(string t){
        
        if(t.size()==0){
            vector<string> bres;
            bres.push_back("");
            return bres;
        }
        
        vector<string> res = getSubSequence(t.substr(1));
        vector<string> fres;
        for(string str : res){
            //Include
            fres.push_back( t[0] + str);
            //Exclude
            fres.push_back( "" + str);
        }
        
        return fres; 
        
    }




    void getSubset(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
        
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        
        //Exclude
        getSubset(nums, output, index+1, ans);
        
        //Include
        output.push_back(nums[index]);
        getSubset(nums, output, index+1, ans);
    }
   
   
   
   
int main(){   
    
    //One major difference b/w Subset & Subsequence: Subset contains empty set but Subsequence does not.

   //Subsequence: A sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements
    //(Not contigious but order is preserved i.e. <a,a,b> & <b,a,a> are not preserving the order)
    //Eg: <a,b,a> = <a>, <b>, <a,b> , <b,a>, <a,a>, <a,b,a>

    
    // vector<string> SubSequences=getSubSequence("abc");
    // for(string ss : SubSequences){
    //         cout<<ss<<" ";
    // }


    
    //Subset: A set is subset of another set if all its elements are contained by that set.
    //(Do not need to be contigous & donot even preserve element order)
    //(Unlike subarray, substring, subsequence sets do not allow duplicates)
    //Eg: {1,2,3} = {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}, {}

    vector<int> v={1,2,3};
    vector<vector<int>> result;
    getSubset(v, {}, 0, result);
    for(vector<int> ss : result){
        for(int i=0; i<ss.size(); i++) cout<<ss[i]<<" ";
        cout<<endl;
    }
}