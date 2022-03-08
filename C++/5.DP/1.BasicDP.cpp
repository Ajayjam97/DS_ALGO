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
   
//GFG
int maximumPathHelper(vector<vector<int>>& Matrix, int r, int c, int N, vector<vector<int>> &dp){
        
        if(r==Matrix.size()-1) return dp[r][c]=Matrix[r][c];
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        int Max=INT_MIN;
        
        Max=max(Max, maximumPathHelper(Matrix, r+1, c, N, dp));
        
        if(c-1>=0)
        Max=max(Max, maximumPathHelper(Matrix, r+1, c-1, N, dp));
        
        if(c+1<Matrix.size())
        Max=max(Max, maximumPathHelper(Matrix, r+1, c+1, N, dp));
        
        return dp[r][c]=Max+Matrix[r][c];
        
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxresult=INT_MIN;
        vector<vector<int>> dp(Matrix.size(), vector<int>(Matrix.size(), -1));
        for(int i=0; i<Matrix[0].size(); i++){
            maxresult=max(maxresult, maximumPathHelper(Matrix, 0, i, N, dp));
        }
        
        return maxresult;
    }
    
    int maximumPath_Tabulated(int N, vector<vector<int>>dp)
  {
      
      for(int i=N-2 ; i>=0 ; i--){
          for(int j=N-1 ; j>=0 ; j--){
              
              int currentCost=dp[i][j];
              int op1=i+1 <= N-1 ? dp[i+1][j] : INT_MIN;
              int op2=i+1 <= N-1 and j-1 >=0 ? dp[i+1][j-1] : INT_MIN;
              int op3=i+1 <= N-1 and j+1 <= N-1 ? dp[i+1][j+1] : INT_MIN;
              int res=max({op1 , op2 , op3});
              dp[i][j]=res+currentCost;
              
          }
      }
      
      int res=INT_MIN;
      for(int j=0 ; j < N ; j++){
          res=max(res , dp[0][j]);
      }
      
      return res;
  }

int main(){

    //vector<int> dp(7, 0);
    //cout<<fib_recursion(6)<<endl<<fib_memoization(6,dp)<<endl<<fib_Tabulation(6)<<endl; //0 1 1 2 3 5 8 13 ................
  
    //vector<int> v = {10, 15, 20};
    //cout<<minCostClimbingStairs_DP(v);

    vector<vector<int>> v = 
    {
        {67, 280, 171, 381, 930, 781, 925, 4, 393, 380, 246, 433, 762, 258, 5, 166, 315},	
        {503, 385, 728, 854, 350, 464, 288, 304, 80, 689 ,56, 313, 843, 92, 379 ,122 ,614},		
        {111, 403, 394, 387, 406, 138, 767, 651, 571, 880, 260, 927, 398, 926, 429, 782, 653},
        {634, 132, 468, 274, 435, 548, 314, 490, 212, 156, 933, 942, 629, 546, 404, 31, 292},
        {142, 436, 781, 260, 86, 703, 140, 697, 630, 537, 622, 410, 318, 275, 44, 801, 94},
        {669, 236, 993, 982, 77, 204, 137, 10, 497, 765, 907, 900, 147, 550, 42, 582, 331},
        {301, 19, 33, 792, 715, 14, 680, 336, 424, 350, 962, 467, 150, 408, 135, 737, 400},
        {468, 814, 956, 956, 175, 452, 72, 433, 704, 218, 983, 97, 799, 665, 749, 169, 49},
        {541, 883, 63, 572, 570, 486, 921, 884, 304, 423, 291, 790, 159, 42, 257, 324, 997},
        {212, 498, 801, 283, 283, 504, 500, 617, 952, 650, 281, 700, 818, 329, 592, 52, 743},
        {164, 621, 228, 436, 856, 883, 858, 498, 672, 17, 540, 928, 340, 536, 139, 190, 336},
        {773, 472, 191, 272, 88, 142, 921, 720, 842, 90, 400, 433, 141, 143, 948, 114, 722},
        {384, 969, 605, 593, 819, 276, 961, 358, 556, 301, 893, 46, 842, 581, 819, 665, 771},
        {90, 104, 265, 363, 823, 106, 452, 574, 890, 945, 68, 190, 58, 790, 925, 378, 746},
        {517, 196, 373, 478, 905, 280, 130, 798, 326, 323, 730, 144, 987 ,500, 585, 90, 764},
        {947, 264, 221, 751, 837, 463, 47, 257, 652, 456, 46, 576, 185, 143, 444, 381, 867},
        {921, 285, 147, 402, 434, 472, 724, 163, 615, 710, 15, 551, 151, 130, 498, 414, 703}
    };

    cout<<maximumPath(17,v)<<endl;

}