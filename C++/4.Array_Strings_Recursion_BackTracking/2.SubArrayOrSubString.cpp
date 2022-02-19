#include <bits/stdc++.h>
using namespace std;


void PrintSubArray(vector<int> v){

    for(int i=0; i<v.size(); i++){

        for(int j=i; j<v.size(); j++){

            for(int k=i; k<=j; k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }
}

void MaxSumSubArray(vector<int> v){

    int MaxSum=INT_MIN;

    ////BRUTE FORCE O(n^3)
    // for(int i=0; i<v.size(); i++){
    //     for(int j=i; j<v.size(); j++){
    //         int sum=0;
    //         for(int k=i; k<=j; k++){
    //             sum+=v[k];
    //         }       
    //         MaxSum=max(MaxSum,sum);
    //     }
    // }
    // cout<<MaxSum<<endl;


    ////CUMULATIVE SUM/ PREFIX SUM O(n^2)
    // vector<int> CurrentSum(v.size()+1);
    // CurrentSum[0] = 0;

    // for(int i=1; i<=v.size(); i++){
    //     CurrentSum[i] = CurrentSum[i-1] + v[i-1];
    // }

    // for(int i=1; i<=v.size(); i++){
    //     int sum=0;
    //     for(int j=0; j<i; j++){
    //         sum = CurrentSum[i] - CurrentSum[j];
    //         MaxSum = max(MaxSum, sum);
    //     }
    // }
    // cout<<MaxSum<<endl;


    ////KADANE'S ALGORITHM O(n)
    // int currentSum = 0;

    // for(int i=0; i<v.size(); i++){
    //     currentSum+=v[i];
    //     if(currentSum<0){
    //         currentSum=0;
    //     }
    //     MaxSum=max(MaxSum,currentSum);
    // }
    // cout<<MaxSum<<endl;


}



int main(){

    //Subarray: Contigious sequence of elements within an array. 
    //Eg1: {1,2,1} = {1}, {1,2}, {1,2,1}, 
    //               {2}, {2,1}

    //Eg2: {1,2,3} = {1}, {1,2}, {1,2,3}, 
    //               {2}, {2,3},
    //               {3}
    
    vector<int> v = {10,20,30,40};
    //PrintSubArray(v);
    //MaxSumSubArray(v);


    //Substring: Same as subarray but in context of a string
    //Eg: "ara" = "a", "r", "ar", "ra", "ara", ""


 
}