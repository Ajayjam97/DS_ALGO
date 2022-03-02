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

vector<pair<int,int>> dirpoints={ {-1,0}, {0,-1}, {1,0}, {0,1} };
vector<char>          direction={'t',  'l',  'd',  'r'};

void FloodFill(vector<vector<int>> maze, int sr, int sc, string asf) {
//write your code here

    if(sr==maze.size()-1&&sc==maze[0].size()-1){
        cout<<asf<<endl;
        return;
    }

    //MARK: Set current visited coordiantes to 1
    maze[sr][sc]=1;

    for(int i=0; i<direction.size(); i++){
        //Calculate x & y coordinates for one of the 4 directions
        int x=sr+dirpoints[i].first; 
        int y=sc+dirpoints[i].second; 
        //Make recursive to next valid direction. Check if the deirection is not out of bounds & not pre visited/blocked
        if(x>=0&&x<maze.size()&&y>=0&&y<maze[0].size()&&maze[x][y]!=1)
        FloodFill(maze,x,y,asf+direction[i]);
    }

    //UNMARK: Unset visited coordinate to 0 when backtracking
    maze[sr][sc]=0;

}

void TargetSumSubsets(vector<int> arr, int idx, string set, int subsetsum, int target) {
    
    if(idx==arr.size()){
        if(subsetsum==target)
        cout<<set<<"."<<endl;
        return;
    }
   
    if(subsetsum+arr[idx]<=target)
    TargetSumSubsets(arr, idx+1, set+to_string(arr[idx])+", ", subsetsum+arr[idx], target);


    TargetSumSubsets(arr, idx+1, set, subsetsum, target);
    
}


int main(){

        //vector<vector<int>> arr(3,vector<int>(3));
        // arr = {
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0},
        //         {0,0,0,0,0,0,0}
        //     };
        //PrintQueenPaths(arr);


        // vector<vector<int>> maze(3,vector<int>(3));
        // maze = {
        //         {0,0,0},
        //         {1,0,1},
        //         {0,0,0}
        //     };
        // FloodFill(maze, 0, 0, "");


        vector<int> arr = {10,20,30,40,50};
        int target=60;
        TargetSumSubsets(arr, 0, "", 0, target);


}