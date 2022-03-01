#include <bits/stdc++.h>
using namespace std;  

void display(vector<vector<int>> arr){
cout<<"--------------------"<<endl;
    for(int i=0; i<arr.size() ;i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
cout<<"--------------------"<<endl;
}

void PrintQueenPaths(vector<vector<int>> arr){

    vector<vector<int>> d = {
                                {-1,0}, //top
                                {-1,1}, //top rigth
                                {0,1},  //right
                                {1,1},  //bottom right
                                {1,0},  //bottom
                                {1,-1}, //bottom left
                                {0,-1}, //left
                                {-1,-1} //top left
                              };

    int r=3; int c=3;

    for(int dir=0; dir<d.size(); dir++){
        for(int rad=1; rad<arr.size(); rad++){

            int x=r+rad*d[dir][0];
            int y=c+rad*d[dir][1];

            if(x>=0&&x<arr.size()&&y>=0&&y<arr[0].size())
            arr[x][y]=1;
        }
        display(arr);
    }
    
}

int main(){

        vector<vector<int>> arr(3,vector<int>(3));

        arr = {
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0}
            };

        PrintQueenPaths(arr);


}