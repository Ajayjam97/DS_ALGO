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

vector<int> StockSpan(vector<int> arr){

    //Using Next Greater on Left
    vector<int> res(arr.size());
    stack<int> stk;

    for(int i=arr.size()-1; i>=0; i--){

        while(!stk.empty()&&arr[stk.top()]<arr[i]){
            res[stk.top()]=i; stk.pop();
        }

        stk.push(i);
    }

    while(!stk.empty()){
        res[stk.top()]=-1; stk.pop();
    }

    for(int i=0; i<res.size(); i++){
        res[i] = i-res[i];
    }

    return res;

}

vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> answer(temperatures.size());
        stack<int> stk;
        
        for(int i=0; i<temperatures.size(); i++){
            
            while(!stk.empty()&&temperatures[stk.top()]<temperatures[i]){
                answer[stk.top()]=i; stk.pop();
            }
            
            stk.push(i);
        }
        
        while(!stk.empty()){
            answer[stk.top()]=0; stk.pop();
        }
        
        for(int i=0; i<answer.size(); i++){
            
            if(answer[i]!=0){
                answer[i]=answer[i]-i;
            }
        }
        
        return answer;
        
    }

int largestRectangleArea(vector<int>& heights) {

        vector<int> lsi(heights.size()); //Left Smaller Index
        vector<int> rsi(heights.size()); //Right Smaller Index
        vector<int> result(heights.size());

        lsi = NextSmallerElementToLeft(heights);
        rsi = NextSmallerElementToRight(heights);
        
        
        for(int i=0; i<result.size(); i++){
            result[i] = rsi[i]-lsi[i]-1;
        }
        
        
}

int main(){
 
    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    for(int i=0; i<arr.size(); i++) cin>>arr[i];
    //arr = NextGreaterElementToRight(arr);
    //arr = NextGreaterElementToLeft(arr);
    //arr = NextSmallerElementToRight(arr);
    //arr = NextSmallerElementToLeft(arr);
    //arr = StockSpan(arr);
    //arr = dailyTemperatures(arr);
    int answer = largestRectangleArea(arr);


    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}
