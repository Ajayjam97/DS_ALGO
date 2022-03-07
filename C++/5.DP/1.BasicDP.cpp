#include <bits/stdc++.h>
using namespace std; 

int fib_recursion(int n){
    
    if( n==0 || n==1 ){ return n;}

    int fibn1 = fib_recursion(n-1);
    int fibn2 = fib_recursion(n-2);

    int fibn = fibn1+fibn2;

    return fibn;
}

int fib_memoization(int n, vector<int> &dp){

    if( n==0 || n==1 ){ return dp[n] = n; }

    //1. If problem already solved, return the result without further calling recursion.
    if(dp[n] != 0){ return dp[n]; }

    int fibn1 = fib_memoization(n-1,dp);
    int fibn2 = fib_memoization(n-2,dp);

    int fibn = fibn1+fibn2;

    //2. If the problem was not solved, store the result in the dp & return the result.
    return dp[n] = fibn;
}

int fib_Tabulation(int n){

    int dp[n + 2];

    dp[0] = 0;
    dp[1] = 1;
 
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbstairs_recursion(int n){
    
    if(n==0){
        return 1;
    }
    
    int count=0;
    for(int jump=1; jump<=3; jump++){
        if(n-jump>=0)
        count+=climbstairs_recursion(n-jump);
    }

    return count;

}

int climbstairs_memoization(int n, vector<int> &dp){
    // write your code here
    if(n==0){
        return dp[n]=1;
    }
    
    if(dp[n]!=0) return dp[n];
    
    int count=0;
    for(int jump=1; jump<=3; jump++){
        if(n-jump>=0)
        count+=climbstairs_memoization(n-jump, dp);
    }

    return dp[n]=count;

}

int climbstairs_tabulation(int N){
    // write your code here

    vector<int> dp(N+1);

    for(int n=0; n<=N; n++){
        
        if(n==0){
            dp[n]=1; 
            continue;
        }

        int count=0;

        for(int jump=1; jump<=3; jump++){
            if(n-jump>=0)
            count+=dp[n-jump];
        }

        dp[n]=count;

    }

    return dp[N];

    // if(n==0){
    //     return dp[n]=1;
    // }
    
    // if(dp[n]!=0) return dp[n];
    
    // int count=0;
    // for(int jump=1; jump<=3; jump++){
    //     if(n-jump>=0)
    //     count+=climbstairs_memo(n-jump, dp);
    // }

    // return dp[n]=count;

}

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

int minCostClimbingStairs_rec(vector<int> &cost, int idx){
	        
        if(idx>=cost.size()) {
            return 0;
        }
	    
        int mincost=1e9;
	    for(int jump=1; jump<=2; jump++){
		
		    int newmincost=minCostClimbingStairs_rec(cost, idx+jump);
            
            if(idx+jump<cost.size())
            newmincost+=cost[idx+jump];
            
            mincost=min(mincost, newmincost);

	    }
        
	    return mincost;
    }

int minCostClimbingStairs(vector<int>& cost){
	    
        int result=minCostClimbingStairs_rec(cost, -1);
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
  
    vector<int> v = {10, 15, 20};
    cout<<minCostClimbingStairs(v);

}