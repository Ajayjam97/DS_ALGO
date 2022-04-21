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

int main() {

cout<<countBinaryString(0,1,"",4)<<endl;

}