#include <bits/stdc++.h>
using namespace std;

int mcm_rec(int i, int j, int arr[]){
        
        if(i==j) return 0;
        
        int mini=1e9;
        
        for(int k=i+1; k<=j; k++){
            int steps = arr[i-1]*arr[k-1]*arr[j] + mcm_rec(i, k-1, arr) + mcm_rec(k, j, arr);
            if(steps<mini) mini=steps;
        }
        
        return mini;
        
    }
    
int mcm_memoized(int i, int j, int arr[], vector<vector<int>> &dp){
        
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        int mini=1e9;
        
        for(int k=i+1; k<=j; k++){
            int steps = arr[i-1]*arr[k-1]*arr[j] + mcm_memoized(i, k-1, arr, dp) + mcm_memoized(k, j, arr, dp);
            if(steps<mini) mini=steps;
        }
        
        return dp[i][j]=mini;
        
    }
  
int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return mcm_memoized(1, N-1, arr, dp);
        return mcm_rec(1, N-1, arr);
    }


int palindromicPartition(string str)
{
    // code here
}

int main() {

    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(5, arr);

}