#include <bits/stdc++.h>
using namespace std; 

int fib_rec(int n){
    
    if( n==0 || n==1 ){ return n;}

    int fibn1 = fib_rec(n-1);
    int fibn2 = fib_rec(n-2);

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


int main(){

    vector<int> dp(7, 0);
    cout<<fib_rec(6)<<endl<<fib_memoization(6,dp)<<endl<<fib_Tabulation(6)<<endl; //0 1 1 2 3 5 8 13 ................


}