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


int cutRod_memoized(int price[], int indx, int rod, vector<vector<int>> &dp){
    
    
    if(rod==0 || indx==dp.size()-1) return dp[indx][rod]=0;
    
    if(dp[indx][rod]!=-1) return dp[indx][rod];
    
    int MaxValue1 = INT_MIN;
    int MaxValue2 = INT_MIN;
    
    //Yes call
    if(rod-indx-1>=0)
    MaxValue1 = cutRod_memoized(price, indx, rod-indx-1, dp) + price[indx];
    
    //No call
    MaxValue2 = cutRod_memoized(price, indx+1, rod, dp);
    
    return dp[indx][rod]=max(MaxValue1, MaxValue2);
    
}

int cutRod_tabulated(int price[], int indx, int rod, vector<vector<int>> &dp){
    
        for(int i=0; i<dp.size(); i++){
           for(int j=0; j<dp[0].size(); j++){
               if(i==dp.size()-1 || j==0){
                   dp[i][j]=0;
               }
           }
       }
       
      for(int i=dp.size()-2; i>=0; i--){
           for(int j=1; j<dp[0].size(); j++){
               
              int MaxValue1 = INT_MIN;
              int MaxValue2 = INT_MIN;
       
              //Yes call
              if(j-i-1>=0)
              MaxValue1 = dp[i][j-i-1] + price[i];
               
              //No call
              MaxValue2 = dp[i+1][j];
               
              dp[i][j]=max(MaxValue1, MaxValue2);
       
          }
      }
       
       
       return dp[0][rod];
    
}

int cutRod(int price[], int n) {
    //code here
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return cutRod_memoized(price, 0, n, dp);
}


long long int coinchange_combination_helper(int S[], int m, int n, int indx, vector<vector<long long int>> &dp){
      
    if(n==0){
        return dp[indx][n]=1;
    }
    
    if(dp[indx][n]!=-1) return dp[indx][n];
    
    long long int ans=0;
    
    for(int i=indx; i<m; i++){
        if(n-S[i]>=0)
        ans+=coinchange_combination_helper(S, m, n-S[i], i, dp);
    }
    
    return dp[indx][n]=ans;
}

long long int coinchange_combination(int S[], int m, int n) {

    // code here.
    vector<vector<long long int>> dp(m+1, vector<long long int>(n+1, -1));
    return coinchange_combination_helper(S, m, n, 0, dp);
    
}


long long int coinchange_permutation_helper(int S[], int m, int n, vector<int> &dp){
      
      if(n==0){
            return dp[n]=1;
        }
        
        if(dp[n]!=-1) return dp[n];
        
        long long int ans=0;
        
        for(int i=0; i<m; i++){
            if(n-S[i]>=0)
            ans+=coinchange_permutation_helper(S, m, n-S[i], dp);
        }
        
        return dp[n]=ans;
}

long long int coinchange_permutation(int S[], int m, int n) {

    // code here.
    vector<int> dp(n+1, -1);
    return coinchange_permutation_helper(S, m, n, dp);
    
}




int main() {

  vector<int> val={1,2,3};
  vector<int> weight={4,5,1};

  unboundedKnapsack(3, val, weight, 4);

}