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

    for(int i=0; i<v.size(); i++){

        for(int j=i; j<v.size(); j++){

            int sum=0;
            for(int k=i; k<=j; k++){
                sum+=v[k];
            }
            
            MaxSum=max(MaxSum,sum);
        }
    }

    cout<<MaxSum<<endl;
}



int main(){

    //Subarray: Contigious sequence of elements within an array

    //Eg1: {1,2,1} = {1}, {1,2}, {1,2,1}, 
    //               {2}, {2,1}

    //Eg2: {1,2,3} = {1}, {1,2}, {1,2,3}, 
    //               {2}, {2,3},
    //               {3}

    vector<int> v = {10,20,30,40};
    PrintSubArray(v);
    v = {-1,4,7,2};
    MaxSumSubArray(v);


    //Substring: Same as subarray but in context of a string
    //Eg: "ara" = "a", "r", "ar", "ra", "ara", ""


    //Subsequence: A sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements
    //(Not contigious but order is preserver i.e. <a,a,b> & <b,a,a> are not preserving the order)
    //Eg: <a,b,a> = <a>, <b>, <a,b> , <b,a>, <a,a>, <a,b,a>, <>


    //Subset: A set is subset of another set if all its elements are contained by that set.
    //(Do not need to be contigous & donot even preserve element order)
    //(Unlike subarray, substring, subsequence sets do not allow duplicates)
    //Eg: {1,2,3} = {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}, {}
}