#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(pair<int,int> p1, pair<int,int> p2){

double v1 = (double) p1.first/p1.second;
double v2 = (double) p2.first/p2.second;

return v1>v2;
}

//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item a[], int n)
{
    // Your code here
    vector<pair<int,int>> arr(n);

    for(int i=0; i<n; i++) arr[i].first = a[i].value;
    for(int i=0; i<n; i++) arr[i].second = a[i].weight;

    sort(arr.begin(), arr.end(), compare);

    double ans=0;

    for(int i=0; i<n; i++){

    if(W>=arr[i].second){
        ans+=arr[i].first;
        W-=arr[i].second;
        continue;
    }

    double remval = (double) arr[i].first/arr[i].second;
    ans+=remval*W;
    break;
    
    }


    return ans;
}

int countBinaryString(int len, int lastadded, string asf, int strngsize){

    if(len==strngsize) return 1;

    int ans=0;
    if(lastadded==1){
        ans+=countBinaryString(len+1, 0, asf+'0', strngsize);
    }
    ans+=countBinaryString(len+1, 1, asf+'1', strngsize);

    return ans;
}

int countBinaryString_Optimized(int len, int lastadded, string asf, int strngsize){

    int zero=1;
    int one=1;
    
    for(int i=2; i<=strngsize; i++){
        int n_zero=one;
        int n_one=one+zero;

        zero=n_zero;
        one=n_one;
    }
    
    return one+zero;
}

int ArrangeBuildings(int n){

    int building=1;
    int space=1;
    
    for(int i=2; i<=n; i++){
        int n_building=space;
        int n_space=building+space;

        space=n_space;
        building=n_building;
    }
    
    long result=building+space;
    return result*result;
}

int countabcsubsequences(string str){

    int a=0;
    int ab=0;
    int abc=0;

    for(int i=0; i<str.size(); i++){
        char ch=str[i];

        if(ch=='a'){
            a=2*a+1;
        }
        
        else if(ch=='b'){
            ab=2*ab+a;
        }
        
        else if(ch=='c'){
            abc=2*abc+ab;
        }
    }

    return abc;
}

int MaxSumNonAdjacent(vector<int> arr, int indx, int status){

    if(indx==-1) return 0;

    int maxsum=-1e9;

    if(status==0){
        maxsum=MaxSumNonAdjacent(arr, indx-1, 1)+arr[indx];
    }
    maxsum=max(maxsum,MaxSumNonAdjacent(arr, indx-1, 0));
    return maxsum;
}

int MaxSumNonAdjacent_memoized(vector<int> arr, int indx, int status, vector<vector<int>> &dp){

    if(indx==-1) return dp[status][indx+1]=0;

    if(dp[status][indx+1]!=0) return dp[status][indx+1];

    int maxsum=-1e9;

    if(status==0){
        maxsum=MaxSumNonAdjacent_memoized(arr, indx-1, 1, dp)+arr[indx];
    }
    maxsum=max(maxsum,MaxSumNonAdjacent_memoized(arr, indx-1, 0, dp));

    return dp[status][indx+1]=maxsum;
}

int MaxSumNonAdjacent_greedy(vector<int> arr){

    int include=0;
    int exclude=0;
    
    for(int i=0; i<arr.size(); i++){
        int n_include=exclude+arr[i];
        int n_exclude=max(include,exclude);

        include=n_include;
        exclude=n_exclude;
    }
    
    return max(include,exclude);
}

int paintHouse(vector<vector<int>> arr){

    int red=0;
    int green=0;
    int blue=0;

    for(int i=0; i<arr.size(); i++){

        //red
        int n_red = min(green,blue)+arr[i][0];
        //green
        int n_green = min(red,blue)+arr[i][1];
        //blue
        int n_blue = min(red,green)+arr[i][2];

        red=n_red;
        green=n_green;
        blue=n_blue;
    }

    return min(red, min(blue, green));
}

int paintfence(int n, int k){
    
    long same=k*1; //ii
    long diff=k*(k-1); //ij
    long total=same+diff;
    
    for(int i=3; i<=n; i++){
        same=diff*1;
        diff=total*(k-1);
        total=same+diff;
    }
    
    return total;
}


int main() {

//cout<<countBinaryString(0,1,"",4)<<endl;

//cout<<countabcsubsequences("abcabc")<<endl;

//cout<<MaxSumNonAdjacent({5,10,10,100,5,6},6,0)<<endl;

vector<vector<int>> dp(2, vector<int>(7, 0));
cout<<MaxSumNonAdjacent_memoized({5,10,10,100,5,6},5,0,dp)<<endl;

cout<<MaxSumNonAdjacent_greedy({5,10,10,100,5,6})<<endl;

cout<<paintHouse({{1,5,7},{5,8,4},{3,2,9},{1,2,4}});

cout<<paintfence(8,3)<<endl;


}