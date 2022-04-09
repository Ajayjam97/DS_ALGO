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


bool isPalindrome(string &str, int i, int j){
        
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++; j--;
        }
        
        return true;
    }
    
int palindromePartitionHelper(string &str, int i, int j, vector<vector<int>> &dp){
        
        if(i>=j) return 0;
        
        if(isPalindrome(str, i, j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mincuts=1e9;
        
        for(int k=i; k<=j-1; k++){
            int steps = 1 + palindromePartitionHelper(str, i, k, dp) + palindromePartitionHelper(str, k+1, j, dp);
            if(steps<mincuts) mincuts=steps;
        }
        
        return dp[i][j]=mincuts;
        
    }
    
int palindromicPartition(string str)
    {
        // code here
        vector<vector<int>> dp(str.size()+1, vector<int>(str.size()+1, -1));
        return palindromePartitionHelper(str, 0, str.size()-1, dp);
    }



int main() {

    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(5, arr);

}