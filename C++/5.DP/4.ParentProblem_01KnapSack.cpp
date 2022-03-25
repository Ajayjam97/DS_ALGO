#include <bits/stdc++.h>
using namespace std; 

void display(vector<vector<int>> arr){
     for(int indx=0; indx<arr.size(); indx++){
            for(int sum=0; sum<arr[0].size(); sum++){
                cout<<arr[indx][sum]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
}


int zero_oneknapSack_memoized(int W, int wt[], int val[], int n, vector<vector<int>> &dp) 
{
       if(n==0){
           return dp[W][n]=0;
       }
       
       
       if(dp[W][n]!=-1) return dp[W][n];
       
       int MaxValue1=INT_MIN;
       int MaxValue2=INT_MIN;
       
       //Consedring deducting nth element
      if(W-wt[n-1] >=0)
       MaxValue1=zero_oneknapSack_memoized(W-wt[n-1], wt, val, n-1, dp)+val[n-1];
       
       //Consedring not deducting nth element
       MaxValue2=zero_oneknapSack_memoized(W, wt, val, n-1, dp);
       
       return dp[W][n]=max(MaxValue1, MaxValue2);
}

int zero_oneknapSack_tabulated(int wt[], int val[], int W, int n, vector<vector<int>> &dp)
    {
        for(int indx=0; indx<dp.size(); indx++){
            for(int cap=0; cap<dp[0].size(); cap++){

                if(indx==0 || cap==0) 
                {
                    dp[indx][cap]=0;
                }

            }
        }
        
        for(int indx=1; indx<dp.size(); indx++){
            for(int cap=1; cap<dp[0].size(); cap++){

                int MaxValue1=INT_MIN;
                int MaxValue2=INT_MIN;

                //No Value
                MaxValue1=dp[indx-1][cap];
                
                //Yes Value
                if(cap-wt[indx-1] >=0)
                MaxValue2=dp[indx-1][cap-wt[indx-1]]+val[indx-1];
                
                dp[indx][cap]=max(MaxValue1,MaxValue2);             
                
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
    
int zero_oneknapSack(int W, int wt[], int val[], int n) 
{ 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       //return zero_oneknapSack_memoized(W, wt, val, n, dp);
       return zero_oneknapSack_tabulated(wt, val, W, n, dp);
       
}


bool isSubsetSum_memoized(vector<int> arr, int indx, int sum, vector<vector<int>> &dp){
        
        if(indx==arr.size()){
            if(sum==0) return dp[indx][sum]=1;
            return dp[indx][sum]=0;
        }
        
        if(dp[indx][sum]!=-1) return dp[indx][sum];
        
        bool YesCallResult=0;
        bool NoCallResult=0;
        
        if(sum-arr[indx]>=0)
        YesCallResult=isSubsetSum_memoized(arr, indx+1, sum-arr[indx], dp);
        
        NoCallResult=isSubsetSum_memoized(arr, indx+1, sum, dp);
    
        return dp[indx][sum]=YesCallResult||NoCallResult;
    }
    
bool isSubsetSum_tabulated(vector<int> arr, int indx, int sum, vector<vector<int>> &dp){

        for(int indx=dp.size()-1; indx>=0; indx--){
            for(int sum=dp[0].size()-1; sum>=0; sum--){
                if(indx==dp.size()-1) dp[indx][sum]=0;
            }
        }

        for(int indx=dp.size()-1; indx>=0; indx--){
            for(int sum=dp[0].size()-1; sum>=0; sum--){
                if(sum==0) dp[indx][sum]=1;
            }
        }
        
        for(int indx=dp.size()-2; indx>=0; indx--){
            for(int sum=dp[0].size()-1; sum>0; sum--){

                bool YesCallResult=0;
                bool NoCallResult=0;
                
                if(sum-arr[indx]>=0)
                YesCallResult=dp[indx+1][sum-arr[indx]];
                NoCallResult=dp[indx+1][sum];
            
                dp[indx][sum]=YesCallResult||NoCallResult;
            }
        }
        
        return dp[0][dp[0].size()-1];
        
    }

bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
        //return isSubsetSum_memoized(arr, 0, sum, dp);
        return isSubsetSum_tabulated(arr, 0, sum, dp);
}

int main(){

    // int wt[]={4,5,1};
    // int val[]={1,2,3};
    // cout<<zero_oneknapSack(4, wt, val, 3);

    vector<int> val={3,34,4,12,5,2};
    cout<<isSubsetSum(val, 30);

}

