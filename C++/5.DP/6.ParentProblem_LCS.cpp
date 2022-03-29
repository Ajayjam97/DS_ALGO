#include <bits/stdc++.h>
using namespace std;


//Function to find the length of longest common subsequence in two strings.
//LCS can be discontinuous
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
    
}

int main() {

    cout<<LongestCommonSubsequence(6,6,"ABCDGH","AEDFHR")<<endl;

}