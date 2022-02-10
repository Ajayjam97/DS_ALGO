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


void MergeOverlappingInterval(vector<pair<int,int>> arr){

    sort(arr.begin(),arr.end());
    stack<pair<int,int>> s;
    s.push(arr[0]);
    
    for(int i=1;i<arr.size();i++){
        
        pair<int,int> p = arr[i];

        if(p.first <= s.top().second){
            //second may get updated
            if(p.second > s.top().second){
                s.top().second = p.second;
            }
        }else{
            s.push(p);
        }
    }

    stack<pair<int,int>> rs;
    while(s.size() > 0){
        rs.push(s.top()); s.pop();
    }

    while(rs.size() > 0){
        pair<int,int> res = rs.top(); rs.pop();
        cout<<res.first<<" "<<res.second<<endl;
    }



}

int main(){
 
    int arrsize; cin>>arrsize;
    vector<pair<int,int>> p;
    //vector<int> arr(arrsize);
    //for(int i=0; i<arr.size(); i++) cin>>arr[i];

    // vector<vector<int>> arr(arrsize, vector<int>(arrsize));
    // for(int i=0; i<arr.size(); i++){
    //     for(int j=0; j<arr[i].size(); j++) cin>>arr[i][j];
    // }

    for(int i=0;i<arrsize;i++){
    int strt,end; cin>>strt; cin>>end;
    p.push_back(make_pair(strt,end));
    }
    
    //celebrityProblem(arr);
    MergeOverlappingInterval(p);
    


    //for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
}


