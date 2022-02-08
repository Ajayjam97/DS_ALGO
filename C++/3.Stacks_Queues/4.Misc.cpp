#include<bits/stdc++.h>
using namespace std;


void celebrityProblem(vector<vector<int>> arr){

    stack<int> stk;

    for(int i=0; i<arr.size(); i++){
        stk.push(i);
    }

    while(stk.size()>1){

        int row = stk.top(); stk.pop();
        int col = stk.top(); stk.pop();

        if(arr[row][col]==1){
            stk.push(col);
        }
        else{
            stk.push(row);
        }
    }

    int potentialCeleb = stk.top(); stk.pop();

    for(int c=0; c<arr[potentialCeleb].size(); c++){
        if(arr[potentialCeleb][c]==1){
             cout<<"none"<<endl;
             return;
        }
    }

    for(int r=0; r<arr.size(); r++){
        if((r!=potentialCeleb)&&(arr[r][potentialCeleb]==0)){
            cout<<"none"<<endl;
            return;
        }
    }

    cout<<potentialCeleb<<endl;
}

int main(){
 
    int arrsize; cin>>arrsize;
    //vector<int> arr(arrsize);
    //for(int i=0; i<arr.size(); i++) cin>>arr[i];

    vector<vector<int>> arr(arrsize, vector<int>(arrsize));
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++) cin>>arr[i][j];
    }

    celebrityProblem(arr);


    //for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}
