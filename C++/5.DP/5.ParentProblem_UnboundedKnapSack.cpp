#include <bits/stdc++.h>

using namespace std;

int unboundedknapSack_memoized(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> &dp) 
{
    
       if(n==0 || W==0){
           return dp[n][W]=0;
       }
       
       
       if(dp[n][W]!=-1) return dp[n][W];
       
       int MaxValue1=INT_MIN;
       int MaxValue2=INT_MIN;
       
       //Consedring deducting nth element
      if(W-wt[n-1] >=0)
       MaxValue1=unboundedknapSack_memoized(W-wt[n-1], wt, val, n, dp)+val[n-1];
       
       //Consedring not deducting nth element
       MaxValue2=unboundedknapSack_memoized(W, wt, val, n-1, dp);
   
       return dp[n][W]=max(MaxValue1, MaxValue2);
       
}

int unboundedknapSack_tabulated(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> &dp) 
{

    for(int indx=0; indx<dp.size(); indx++){
        for(int cap=0; cap<dp[0].size(); cap++){
            if(indx==0 || cap==0){
                dp[indx][cap]=0;
            }
        }
    }

    for(int indx=1; indx<dp.size(); indx++){
        for(int cap=1; cap<dp[0].size(); cap++){

               int MaxValue1=INT_MIN;
               int MaxValue2=INT_MIN;
       
              if(cap-wt[indx-1] >=0)
               MaxValue1=dp[indx][cap-wt[indx-1]]+val[indx-1];

               MaxValue2=dp[indx-1][cap];
   
               dp[indx][cap]=max(MaxValue1, MaxValue2);

        }
    }

    return dp[dp.size()-1][dp[0].size()-1];
       
}

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {

       vector<vector<int>> dp(n+1, vector<int>(cap+1, -1));
       cout<<unboundedknapSack_tabulated(cap, weight, val, n, dp);

}


int main() {

  vector<int> val={1,2,3};
  vector<int> weight={4,5,1};

  unboundedKnapsack(3, val, weight, 4);


}