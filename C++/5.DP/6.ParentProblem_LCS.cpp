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

int LongestCommonSubsequence(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x+1, vector<int>(y+1, -1));
    return LongestCommonSubsequence_memoized(x, y, s1, s2, dp);
    return LongestCommonSubsequence_tabulated(x, y, s1, s2, dp);
    
}


int LongestCommonSubstring_recursive(string X, string Y,int x, int y, vector<vector<int>> &dp, int count)
{

    if (x == 0 || y == 0)
        return count;
        

    if (X[x - 1] == Y[y - 1]) {
        count = LongestCommonSubstring_recursive(X, Y, x - 1, y - 1, dp, count + 1);
    }
    count = max(count,
                max(LongestCommonSubstring_recursive(X, Y, x, y - 1, dp, 0),
                    LongestCommonSubstring_recursive(X, Y, x - 1, y, dp, 0)));
    return count;
}

int LongestCommonSubstring_tabulated(string X, string Y,int x, int y, vector<vector<int>> &dp, int count)
{

    for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
               
                if(X[i-1]==Y[j-1]){
                     dp[i][j]=dp[i-1][j-1]+1;
                } 
                else{
                    dp[i][j]=0;
                }
                    
        
            }
        }
        
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                if(dp[i][j]>count){
                    count=dp[i][j];
                }
            }
        }
        
        return count;
}

int LongestCommonSubstring(string S1, string S2, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return LongestCommonSubstring_recursive(S1, S2, n, m, dp, 0);
    return LongestCommonSubstring_tabulated(S1, S2, n, m, dp, 0);
}


int print_longest_common_subsequence(string s1, string s2, int x, int y, vector<vector<int>> dp)
{
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
        
            int len=dp[x][y];
            string ans="";
            for(int i=0; i<len; i++) ans+='$';

            int index=len-1;
            int i=x; int j=y;

            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    ans[index] = s1[i-1];
                    index--;
                    i--; j--;
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }

            cout<<ans;
	        
}

int main() {

    //cout<<LongestCommonSubsequence(6,6,"ABCDGH","AEDFHR")<<endl;
    //cout<<LongestCommonSubstring("ABCDGH","ACDGHR",6,6)<<endl;
    vector<vector<int>> dp(7, vector<int>(7));
    print_longest_common_subsequence("ABCDGH","AEDFHR",6,6,dp);

}