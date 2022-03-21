#include <bits/stdc++.h>
using namespace std; 


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

//GFG
int maxGoldHelper(int row, int col, vector<vector<int>> &M, vector<vector<int>> &dp){
        
        if(col==M[0].size()-1) return dp[row][col]=M[row][col];
        
        if(dp[row][col]!=-1) return dp[row][col]; 
        
        int maxgold=INT_MIN;
        
        if(row-1>=0&&col+1<M[0].size()) maxgold=max(maxgold, maxGoldHelper(row-1, col+1, M, dp));
        
        if(col+1<M[0].size()) maxgold=max(maxgold, maxGoldHelper(row, col+1, M, dp));
        
        if(row+1<M.size()&&col+1<M[0].size()) maxgold=max(maxgold, maxGoldHelper(row+1, col+1, M, dp));
        
        return dp[row][col]=maxgold+M[row][col];
    }
    
int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxgold = INT_MIN;
        
        vector<vector<int>> dp(M.size(), vector<int>(M[0].size(), -1));
        
        for(int row=0; row<n; row++){
            maxgold=max(maxgold, maxGoldHelper(row, 0, M, dp));
        }
        
        return maxgold;
    }

int maxGold_Tabulated(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {

  //write your code here
  int maxgold=INT_MIN;
  
  for(int col=arr[0].size()-1; col>=0; col--){  
      for(int row=0; row<arr.size(); row++){
          
          if(col==arr[0].size()-1){
                dp[row][col]=arr[row][col];
          }
          else if(row==0){
                dp[row][col]=max(dp[row][col+1], dp[row+1][col+1])+arr[row][col];
          }
          else if(row==arr.size()-1){
                dp[row][col]=max(dp[row-1][col+1], dp[row][col+1])+arr[row][col];
          }
          else{
                dp[row][col]=max(dp[row-1][col+1], max(dp[row][col+1], dp[row+1][col+1]))+arr[row][col];
          }
          
          maxgold=max(maxgold, dp[row][col]);     
      }
  }
  
  return maxgold;
}


bool TargetSumSubset(int sum, vector<int> arr, int tar){

    if(arr.size()==0){
    if(sum == tar) return true;
    else return false;
    }
 
    int num = arr[arr.size()-1]; arr.pop_back();
    
    bool res1 = false;
    bool res2 = false;

    res1 = TargetSumSubset(sum+num, arr, tar);
    res2 = TargetSumSubset(sum, arr, tar);

    return (res1 || res2);    

}

bool TargetSumSubsetMemo(vector<int> arr, int index, int tar, vector<vector<bool>> dp) {
        if(tar == 0) return dp[index][tar] = true; 
        if(index == 0) {
            return dp[index][tar] = false;
        }

        if(dp[index][tar] != false) {
            return dp[index][tar];
        }

        bool res = false;
        // yes call
        if(tar - arr[index] >= 0) {
            res = TargetSumSubsetMemo(arr, index - 1, tar - arr[index], dp);
        }
        // no call
        res = res || TargetSumSubsetMemo(arr, index - 1, tar, dp);
        return dp[index][tar] = res;
    }

bool TargetSumSubsetTab(vector<int> arr, int tar){

    vector<vector<bool>> dp(arr.size()+1, vector<bool>(tar + 1));

    for(int indx = 0; indx < dp.size(); indx++){
        for(int target = 0; target < dp[0].size(); target++){
            if(target == 0){
                dp[indx][target] = true;
            }
            else if(indx == 0){
                dp[indx][target] = false;
            }
            else{
                int val = arr[indx-1];
                if(target < val){
                    //no call
                    dp[indx][target] = dp[indx-1][target];
                }            
                else{
                    //no || yes call
                    dp[indx][target] = dp[indx-1][target] || dp[indx-1][target-val];

                } 

            }
        }
    }

    return dp[dp.size()-1][dp[0].size()-1];    
     
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

int main(){

    // vector<vector<int>> v = 
    // {
    //     {67, 280, 171, 381, 930, 781, 925, 4, 393, 380, 246, 433, 762, 258, 5, 166, 315},	
    //     {503, 385, 728, 854, 350, 464, 288, 304, 80, 689 ,56, 313, 843, 92, 379 ,122 ,614},		
    //     {111, 403, 394, 387, 406, 138, 767, 651, 571, 880, 260, 927, 398, 926, 429, 782, 653},
    //     {634, 132, 468, 274, 435, 548, 314, 490, 212, 156, 933, 942, 629, 546, 404, 31, 292},
    //     {142, 436, 781, 260, 86, 703, 140, 697, 630, 537, 622, 410, 318, 275, 44, 801, 94},
    //     {669, 236, 993, 982, 77, 204, 137, 10, 497, 765, 907, 900, 147, 550, 42, 582, 331},
    //     {301, 19, 33, 792, 715, 14, 680, 336, 424, 350, 962, 467, 150, 408, 135, 737, 400},
    //     {468, 814, 956, 956, 175, 452, 72, 433, 704, 218, 983, 97, 799, 665, 749, 169, 49},
    //     {541, 883, 63, 572, 570, 486, 921, 884, 304, 423, 291, 790, 159, 42, 257, 324, 997},
    //     {212, 498, 801, 283, 283, 504, 500, 617, 952, 650, 281, 700, 818, 329, 592, 52, 743},
    //     {164, 621, 228, 436, 856, 883, 858, 498, 672, 17, 540, 928, 340, 536, 139, 190, 336},
    //     {773, 472, 191, 272, 88, 142, 921, 720, 842, 90, 400, 433, 141, 143, 948, 114, 722},
    //     {384, 969, 605, 593, 819, 276, 961, 358, 556, 301, 893, 46, 842, 581, 819, 665, 771},
    //     {90, 104, 265, 363, 823, 106, 452, 574, 890, 945, 68, 190, 58, 790, 925, 378, 746},
    //     {517, 196, 373, 478, 905, 280, 130, 798, 326, 323, 730, 144, 987 ,500, 585, 90, 764},
    //     {947, 264, 221, 751, 837, 463, 47, 257, 652, 456, 46, 576, 185, 143, 444, 381, 867},
    //     {921, 285, 147, 402, 434, 472, 724, 163, 615, 710, 15, 551, 151, 130, 498, 414, 703}
    // };

    //cout<<maximumPath(17,v)<<endl;


}