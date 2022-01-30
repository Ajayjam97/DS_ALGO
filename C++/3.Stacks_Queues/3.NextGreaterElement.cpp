#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElementToRight(vector<int> arr){

    stack<int> stk;
    vector<int> res(arr.size());

    for(int i=0; i<arr.size(); i++){

        while((!stk.empty())&&(arr[i]>arr[stk.top()])){
            int index=stk.top(); stk.pop();
            res[index]=arr[i];
        }
        stk.push(i);
    }

    while(!stk.empty()){
        res[stk.top()] = -1; stk.pop();
    }
    return res;
}

vector<int> NextGreaterElementToLeft(vector<int> arr){

    stack<int> stk; 
    vector<int> res(arr.size());

    for(int i=arr.size()-1; i>=0; i--){
        while((!stk.empty())&&(arr[stk.top()]<arr[i])){
            res[stk.top()]=arr[i]; stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()){
        res[stk.top()]=-1; stk.pop();
    }

    return res;
}

vector<int> NextSmallerElementToRight(vector<int> arr){

        stack<int> stk;
    vector<int> res(arr.size());

    for(int i=0; i<arr.size(); i++){

        while((!stk.empty())&&(arr[i]<arr[stk.top()])){
            int index=stk.top(); stk.pop();
            res[index]=arr[i];
        }
        stk.push(i);
    }

    while(!stk.empty()){
        res[stk.top()] = -1; stk.pop();
    }
    return res;

}

vector<int> NextSmallerElementToLeft(vector<int> arr){

        stack<int> stk; 
    vector<int> res(arr.size());

    for(int i=arr.size()-1; i>=0; i--){
        while((!stk.empty())&&(arr[stk.top()]>arr[i])){
            res[stk.top()]=arr[i]; stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()){
        res[stk.top()]=-1; stk.pop();
    }

    return res;
}

int main(){
 
    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++) cin>>arr[i];
    //arr = NextGreaterElementToRight(arr);
    //arr = NextGreaterElementToLeft(arr);
    //arr = NextSmallerElementToRight(arr);
    arr = NextSmallerElementToLeft(arr);
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}