#include <bits/stdc++.h>
using namespace std; 

int MinJumps_recursive(int i, int n, vector<int>& jumps, vector<int>& dp)
{
  // write your code here
    if(i==n){
        return 0;
    }
    
    int minmove=1e9;

    for(int jump=1; jump<=jumps[i]; jump++){
        
        if(i+jump<=n)   {
            
            minmove=min(minmove, MinJumps_recursive(i+jump, n, jumps, dp));
            
        }
        
    }
    
    return minmove+1;
}

int MinJumps_memoization(int i, int n, vector<int>& jumps, vector<int>& dp)
{
  // write your code here
    if(i==n){
        return dp[i]=0;
    }

    if(dp[i]!=0) return dp[i];
    
    int minmove=1e9;
    for(int jump=1; jump<=jumps[i]; jump++){
        
        if(i+jump<=n)   {
            
            minmove=min(minmove, MinJumps_memoization(i+jump, n, jumps, dp));
            
        }
        
    }
    
    return dp[i]=minmove+1;
}

int MinJumps_tabulation(int i, int n, vector<int>& jumps)
{
  // write your code here
  vector<int> dp(n+1);

  for(int i=n; i>=0; i--){

    if(i==n){
          dp[i]=0;
          continue;
    }

    int minmove=1e9;
    for(int jump=1; jump<=jumps[i]; jump++){
        if(i-jump<=n)   {            
            minmove=min(minmove, dp[i+jump]);
        }   
    }

    dp[i]=minmove+1;


  }
    
  return dp[0];
    // if(i==n){
    //     return dp[i]=0;
    // }

    // if(dp[i]!=0) return dp[i];
    
    // int minmove=1e9;
    // for(int jump=1; jump<=jumps[i]; jump++){
        
    //     if(i+jump<=n)   {
            
    //         minmove=min(minmove, MinJumps_memoization(i+jump, n, jumps, dp));
            
    //     }
        
    // }
    
    // return dp[i]=minmove+1;
}

int minCostClimbingStairsHelper_Rec(vector<int> &cost, int idx){
	        
        if(idx>=cost.size()) {
            return 0;
        }
	    
        int mincost=1e9;
	    for(int jump=1; jump<=2; jump++){
		
		    int newmincost=minCostClimbingStairsHelper_Rec(cost, idx+jump);
            
            if(idx+jump<cost.size())
            newmincost+=cost[idx+jump];
            
            mincost=min(mincost, newmincost);

	    }
        
	    return mincost;
    }

int minCostClimbingStairs_Rec(vector<int>& cost){
	    
        int result=minCostClimbingStairsHelper_Rec(cost, -1);
	    return result;
}

int minCostClimbingStairsHelper_DP(vector<int> &cost, int idx, vector<int> &dp){
	        
        if(idx>=cost.size()) {
            return dp[idx]=0;
        }
	    
        
        if(dp[idx]!=0) return dp[idx];
        
        int mincost=1e9;
	    for(int jump=1; jump<=2; jump++){
		
		    int newmincost=minCostClimbingStairsHelper_DP(cost, idx+jump, dp);
            
            if(idx+jump-1<cost.size())
            newmincost+=cost[idx+jump-1];
            
            mincost=min(mincost, newmincost);

	    }
        
	    return dp[idx]=mincost;
}

int minCostClimbingStairs_DP(vector<int>& cost){
	    
        vector<int> dp(cost.size()+2);
        int result=minCostClimbingStairsHelper_DP(cost, 0, dp);
	    return result;
}


int main(){

    //vector<int> dp(7, 0);
    //cout<<fib_recursion(6)<<endl<<fib_memoization(6,dp)<<endl<<fib_Tabulation(6)<<endl; //0 1 1 2 3 5 8 13 ................
  
    //vector<int> v = {10, 15, 20};
    //cout<<minCostClimbingStairs_DP(v);


}