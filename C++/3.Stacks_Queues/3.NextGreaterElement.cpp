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
        res[stk.top()] = arr.size(); stk.pop();
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

vector<int> LSI(vector<int> heights){

    vector<int> res(heights.size());
    stack<int> stk;

    for(int i=heights.size()-1; i>=0; i--){

        while(!stk.empty()&&heights[i]<heights[stk.top()]){
            res[stk.top()]=i; stk.pop();
        }
        stk.push(i);
    }

    while(stk.size()>0){
        res[stk.top()]=-1; stk.pop();
    }

    return res;
}

vector<int> RSI(vector<int> heights){
    
    vector<int> res(heights.size());
    stack<int> stk;

    for(int i=0; i<heights.size(); i++){

        while(!stk.empty()&&heights[i]<heights[stk.top()]){
            res[stk.top()]=i; stk.pop();
        }
        stk.push(i);
    }

    while(stk.size()>0){
        res[stk.top()]=heights.size(); stk.pop();
    }

    return res;
}

int largestRectangleArea(vector<int>& heights) {

        vector<int> lsi(heights.size()); //Left Smaller Index
        vector<int> rsi(heights.size()); //Right Smaller Index
        vector<int> result(heights.size());

        lsi = LSI(heights); //Make sure to include -1 index for elements not having smallest element in the array
        rsi = RSI(heights); //Make sure to include  size of array as index for elements not having smallest element in the array
        
        
        for(int i=0; i<result.size(); i++){
            result[i] = heights[i]*(rsi[i]-lsi[i]-1);
        }

        return *max_element(result.begin(), result.end());
        
        
}

int maximalRectangle(vector<vector<char>>& matrix) {

    if(matrix.size()==0) return 0;
        
        vector<int> arr(matrix[0].size());

        int res=0;


        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                if(matrix[i][j]=='0'){
                    arr[j]=0;
                }
                else{
                    arr[j] += matrix[i][j] - '0';
                }
            }
            res = max(res, largestRectangleArea(arr));
        }

        return res;
    }

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // vector<int> res;
        // for(int i=0; i<=nums.size()-k; i++){
        //     int max=nums[i];
        //     for(int j=i; j<=i+k-1; j++){
        //         if(nums[j]>max){
        //             max=nums[j];
        //         }
        //     }
        //     res.push_back(max);
        // }
        // return res;
         
    }

int main(){
 
    int arrsize; cin>>arrsize;
    vector<int> arr(arrsize);

    vector<vector<char>> carr(5, vector<char>(5, '0'));
    vector<vector<char>> carr2
    {
       {'1', '0', '1', '0', '0'},
       {'1', '0', '1', '1', '1'},
       {'1', '1', '1', '1', '1'},
       {'1', '0', '0', '1', '0'}
    };

    for(int i=0; i<arr.size(); i++) cin>>arr[i];

    //arr = NextGreaterElementToRight(arr);
    //arr = NextGreaterElementToLeft(arr);
    //arr = NextSmallerElementToRight(arr);
    //arr = NextSmallerElementToLeft(arr);
    //arr = StockSpan(arr);
    //arr = dailyTemperatures(arr);
    //cout<<largestRectangleArea(arr)<<endl;
    //cout<<maximalRectangle(carr2)<<endl;
    int k; cin>>k; arr = maxSlidingWindow(arr, k);

    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}
