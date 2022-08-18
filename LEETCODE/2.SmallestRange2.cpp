#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {
        
        pair<int, int> p;

        sort(arr.begin(), arr.end());
        int n=arr.size();
        int minheight = arr[0];
        int maxheight = arr[n-1];
        int ans=maxheight - minheight;
        
        for(int i=0; i<n-1; i++){
            
            maxheight=max(arr[i]+k, arr[n-1]-k);
            minheight=min(arr[0]+k,arr[i+1]-k);
            ans=min(ans, maxheight-minheight);
            
        }
        
        return ans;
        
    }
};

int main(){

    Solution sol;
    vector<int> arr = {8, 1, 5, 4, 7, 5, 7, 9, 4, 6};
    cout<<sol.smallestRangeII(arr, 5)<<endl;

}