#include<bits/stdc++.h>
using namespace std;

    int minJumpsHelper(int arr[], int indx, int n, vector<int> &dp){
        
        if(n<=1) return 0;
        
        if(indx >= n - 1) return dp[indx]=0;
        
        if(dp[indx]!=-1) return dp[indx];

        int minjumps = INT_MAX-5;
    
        if(arr[indx]!=0){
            
            for(int i = 1; i <= arr[indx]; i++){
                minjumps = min(minjumps, 1 + minJumpsHelper(arr, indx+i, n, dp));
            }
            
        }
            
        return dp[indx]=minjumps;
        
    }
  
    int minJumps(int arr[], int n){
    
        vector<int> dp(10e7, -1);
        int result = minJumpsHelper(arr, 0, n, dp);
        if(result==INT_MAX-5) return -1;
        return result;
    }

//   int dfs(int node,vector<int>&vis,vector<int>adj[]){
// 		if(vis[node]) return 0;
// 		vis[node] = 1;
// 		int res = 0;
// 		for(auto edge:adj[node]) if(!vis[edge]) res+=dfs(edge,vis,adj);
// 			return res+1;
// 	}

// 	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
// 		vector<int>vis(n,0);
// 		for(auto x:restricted) vis[x] = 1;
// 		vector<int>adj[n];
// 		for(auto node:edges) adj[node[0]].push_back(node[1]),adj[node[1]].push_back(node[0]);
// 		return dfs(0,vis,adj);
// 	}



    int dfs(vector<int>& visited, int src, vector<vector<int>> adj){
        
        if(visited[src]) return 0;
        visited[src]=1;
        
        int result=0;
        
        for(int nbr: adj[src]){
            if(!visited[nbr]){
                result+=dfs(visited, nbr, adj);
            }
        }
        
        return result+1;
        
    }
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        
        unordered_set<int> rs(begin(restricted), end(restricted)); 
        
        for(int i=0; i<n-1; i++){  
            if(rs.count(edges[i][0])+rs.count(edges[i][1])==0){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            }
        }
        
        for(int i=0; i<restricted.size(); i++){
            visited[restricted[i]]=1;
        }
        

        return dfs(visited, 0, adj);
        
    }

    int getPairsCount(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int x = 0, c = 0, y, z;
        for (int i = 0; i < n - 1; i++) {
            x = k - arr[i];
        
            // Lower bound from i+1
            int y = lower_bound(arr + i + 1,arr + n, x) - arr;
            
            // Upper bound from i+1
            int z = upper_bound(arr + i + 1,arr + n, x) - arr;
            cout<<y<<" "<<z<<endl;
            c = c + z - y;
        }
        return c;
    }


    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> result;
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            res=res^nums[i];
            result.push_back(res);
        }

        return result;
    }


    int countbits(int n){
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        
        return count;
    }
    
    
    int countSetBits(int n)
    {
        // Your logic here
        int result=0;
        for(int i=1; i<=n; i++){
            result+=countbits(i);
        }
        
        return result;
    }

        int setSetBit(int x, int y, int l, int r){
        // code here
        int mask=0;
        
        while(r>=l){
            mask|=1<<(r-1);
            mask|=1<<(l-1);
            l++; r--;
        }

        cout<<mask<<endl;
        
        y=y&mask;
        x=x|y;
        
        return x;
    }

    
int main(){

    // int arr[] = {0, 1, 1, 1, 1};
    // cout<<minJumps(arr, 5)<<endl;

    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
    // vector<int> restricted = {4,2,1};
    // cout<<reachableNodes(n, edges, restricted);

    // int arr[] = { 1, 5, 7, -1, 5 };
    // int n = sizeof(arr) / sizeof(arr[0]); 
    // cout << "Count of pairs is "<< getPairsCount(arr, n, 6);

    // vector<int> result;
    // result = singleNumber({1, 2, 3, 2, 1, 4});
    // for(int i=0; i<result.size(); i++){
    //     cout<<result[i]<<" ";
    // }

    // cout<<countSetBits(4);

    cout<<setSetBit(16,2,1,3);

}