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

            cout<<ans<<endl;
	        
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


int ShortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        int lcs=LongestCommonSubsequence_tabulated(m,n,X,Y,dp);
        
        return ((m+n)-lcs);
    }

int print_shortest_Common_Supersequence(string s1, string s2, int x, int y, vector<vector<int>> dp)
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
        
            string ans="";
            int i=x; int j=y;

            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    ans += s1[i-1];
                    i--; j--;
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    ans += s1[i-1];
                    i--;
                }
                else{
                    ans += s2[j-1];
                    j--;
                }
            }

            while(i>0){
                ans+=s1[i-1];
                i--;
            }

            while(j>0){
                ans+=s2[j-1];
                j--;
            }

            reverse(ans.begin(), ans.end());

            cout<<ans<<endl;
	        
}


//Min numer of insertions & deletions
int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int x=str1.size(); int y=str2.size();
	    vector<vector<int>> dp(x+1, vector<int>(y+1));
	    int lcs=LongestCommonSubsequence_tabulated(x, y, str1, str2, dp);
	    
	    int deletions=x-lcs;    
	    int insertions=y-lcs;   
	    
	    return (deletions+insertions);
	    
	}

//Longest palindromic subsequence
int longestPalinSubseq(string A) {
        //code here
        string a=A;
        reverse(A.begin(), A.end());
        string b=A;
        
        vector<vector<int>> dp(a.size()+1, vector<int>(a.size()+1, -1));
        return LongestCommonSubsequence_tabulated(a.size(), a.size(), a, b, dp);
    }

//Longest palindromic substring
string longestPalindrome(string S){
        // code here 
        string answer="";
        int size=0;
        for(int i=0; i<S.size(); i++){
            for(int j=1; j<=S.size()-i; j++){
                string temp=S.substr(i,j);
                string actual=temp;
                reverse(temp.begin(), temp.end());
                string rev=temp;
                if(actual==rev){
                    if(temp.size()>size){
                        size=temp.size(); answer=temp;
                    }
                }
            }
        }

        return answer;
}


int longestPalindromeDP(string S){
        // code here 
        vector<vector<bool>> dp(S.size(), vector<bool>(S.size()));
        int len=0;

        for(int gap=0; gap<S.size(); gap++){
            for(int i=0, j=gap; j<S.size(); i++, j++){
                
                if(gap==0){
                    dp[i][j]=true;
                }
                else if(gap==1){
                    if(S[i]==S[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if((S[i]==S[j])&&(dp[i+1][j-1]==true)){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }

                if(dp[i][j]){
                    len=gap+1;
                }
            }
        }

        return len;
}


//Longest increasing subsequence
int longestSubsequencehelper(int indx, int n, int a[], int prev_indx, vector<vector<int>> &dp){
        
       if(indx==n){
           return dp[indx][prev_indx+1]=0;
       }
       
       if(dp[indx][prev_indx+1]!=-1) return dp[indx][prev_indx+1];
       
       int ans=longestSubsequencehelper(indx+1,n,a, prev_indx, dp);
       
       if(prev_indx == -1 || a[indx]>a[prev_indx])
       ans=max(ans,longestSubsequencehelper(indx+1,n,a, indx, dp)+1);
       
       if(prev_indx == -1) return dp[indx][prev_indx+1]=ans;
       
       return dp[indx][prev_indx+1]=ans;
       
    }
    
//Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
       return longestSubsequencehelper(0,n,a, -1, dp);
    }



int main() {

    vector<vector<int>> dp(7, vector<int>(7));
    //cout<<LongestCommonSubsequence(6,6,"ABCDGH","AEDFHR")<<endl;
    //print_longest_common_subsequence("ABCDGH","AEDFHR",6,6,dp);

    //cout<<LongestCommonSubstring("ABCDGH","ACDGHR",6,6)<<endl;
    
    //cout<<ShortestCommonSupersequence("ABCDGH","AEDFHR",6,6)<<endl;
    //print_shortest_Common_Supersequence("ABCDGH","AEDFHR",6,6,dp);

    //cout<<minOperations("ABCDGH","AEDFHR")<<endl;  //ABCEDFGHR

    //cout<<longestPalinSubseq("agbcba")<<endl;

    //cout<<longestPalinSubseq("abccbc")<<endl;

    //cout<<longestPalindrome("abccbc")<<endl;

    cout<<longestPalindromeDP("abccbc")<<endl;

}