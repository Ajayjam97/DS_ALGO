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

int mazeTraversal(int sr, int sc, int dr, int dc, vector<vector<int>> arr){
    
    if((sr==dr)&&(sc==dc)){ return arr[sr][sc]; }

    int mincost = (int)1e9;

    if(sc+1 <= dc)
    mincost = min(mincost,mazeTraversal(sr, sc+1, dr, dc, arr));
    if(sr+1 <= dr)
    mincost = min(mincost,mazeTraversal(sr+1, sc, dr, dc, arr));

    return (mincost + arr[sr][sc]);

}

int mazeTraversalmemo(int sr, int sc, int dr, int dc, vector<vector<int>> arr, vector<vector<int>> dp){
    
    if((sr==dr)&&(sc==dc)){ return dp[sr][sc] = arr[sr][sc]; }

    int mincost = (int)1e9;

    if(dp[sr][sc]!=0){
        return dp[sr][sc];
    }

    if(sc+1 <= dc)
    mincost = min(mincost,mazeTraversalmemo(sr, sc+1, dr, dc, arr, dp));
    if(sr+1 <= dr)
    mincost = min(mincost,mazeTraversalmemo(sr+1, sc, dr, dc, arr, dp));

    return dp[sr][sc]=(mincost + arr[sr][sc]);


}

int mazeTraversaltabulated(int sr, int sc, int dr, int dc, vector<vector<int>> arr, vector<vector<int>> dp){
    
    for(int i = dr; i>=0; i--){
        for(int j = dc; j>=0; j--){

            if(i==dr && j==dc){
                dp[i][j] = arr[i][j];
                continue;
            }

            int mincost = (int)1e9;

            if(j+1 <= dc)
            mincost = min(mincost,dp[i][j+1]);
            
            if(i+1 <= dr)
            mincost = min(mincost,dp[i+1][j]);

            dp[i][j]=(mincost + arr[i][j]);

        }
    }

    return dp[0][0];

   
}

int main(){

    //vector<int> dp(7, 0);
    //cout<<fib_recursion(6)<<endl<<fib_memoization(6,dp)<<endl<<fib_Tabulation(6)<<endl; //0 1 1 2 3 5 8 13 ................
  
    vector<int> v = {10, 15, 20};
    cout<<minCostClimbingStairs_DP(v);

}