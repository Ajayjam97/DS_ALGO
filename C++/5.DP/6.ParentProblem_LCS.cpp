#include <bits/stdc++.h>
using namespace std;


//Function to find the length of longest common subsequence in two strings.
//LCS can be discontinuous
int LongestCommonSubsequence_tabulated(int x, int y, string s1, string s2, vector<vector<int>> &dp){
        
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
               
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                } 
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
        
            }
        }
        
        return dp[x][y];
        
    }

int LongestCommonSubsequence_memoized(int x, int y, string s1, string s2, vector<vector<int>> &dp){

        if(x==0||y==0) return dp[x][y]=0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int result=0;
        if(s1[x-1]==s2[y-1]){
            result=LongestCommonSubsequence_memoized(x-1,y-1,s1,s2, dp)+1;
        } 
        else{
            result=max(LongestCommonSubsequence_memoized(x,y-1,s1,s2, dp),LongestCommonSubsequence_memoized(x-1,y,s1,s2, dp));
        }
        
        return dp[x][y]=result;

}

int LongestCommonSubsequence(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
    return LongestCommonSubsequence_memoized(x, y, s1, s2, dp);
    return LongestCommonSubsequence_tabulated(x, y, s1, s2, dp);
    
}


int LongestCommonSubstring (string S1, string S2, int n, int m)
{
    // your code here
}


int main() {

    cout<<LongestCommonSubsequence(6,6,"ABCDGH","AEDFHR")<<endl;

}