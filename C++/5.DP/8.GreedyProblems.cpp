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


int main() {



}