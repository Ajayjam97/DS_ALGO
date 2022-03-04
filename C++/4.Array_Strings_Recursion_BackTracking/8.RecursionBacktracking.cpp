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

bool CanPlace(vector<vector<int>> board, int sr, int sc){
    //return true;
    
    vector<vector<int>> directions = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

    for(int dir=0; dir<directions.size(); dir++){
        for(int rad=1; rad<board.size(); rad++){

            int x=sr+rad*directions[dir][0];
            int y=sc+rad*directions[dir][1];

            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()){
                if(board[x][y]==1) return false;
            }

        }
    }

    return true;
}

void NQueens(vector<vector<int>> board, int sr, int sc, int qpsf, string ansf){

    if(sr==board.size()){
        if(qpsf==board.size())
            cout<<ansf<<endl;
            return;
    }

    if(sc+1<board[0].size()){  //Next column

        if(CanPlace(board, sr,sc)){   //Next column is valid
            board[sr][sc]=1;
            NQueens(board, sr+1, 0, qpsf+1, ansf+'('+to_string(sr)+','+to_string(sc)+") ");
            board[sr][sc]=0;
        }
        //Do not Place the queen
        NQueens(board, sr, sc+1, qpsf, ansf);
    }
    else{   //Next column is not valid

        if(CanPlace(board, sr,sc)){   //Place the queen
            board[sr][sc]=1;
            NQueens(board, sr+1, 0, qpsf+1, ansf+'('+to_string(sr)+','+to_string(sc)+") ");
            board[sr][sc]=0;
        }
        //Do not Place the queen
        NQueens(board, sr+1, 0, qpsf, ansf);
    }
}

//GFG
bool IsValidPlace(vector<vector<int>> board, int sr, int sc){
    //return true;

    int i=sr; int j=sc;
    
    while(i>=0&&j<board.size()){
        if(board[i][j]==1) return false;
        i--; j++;
    }
    
    i=sr; j=sc;
    
    while(i>=0&&j>=0){
        if(board[i][j]==1) return false;
        i--; j--;
    }
    
    i=sr;
    
    while(i>=0){
        if(board[i][sc] == 1) return false;
        i--;
    }

    return true;
}

void QueenHelper(vector<vector<int>> board, int sr, vector<int> &ans, vector<vector<int>> &result){
        
        if(sr==board.size()){
            result.push_back(ans);
            return;
        }
        
        for(int sc=0; sc<board.size(); sc++){
            
            if(IsValidPlace(board, sr, sc)){
                board[sr][sc]=1;    ans.push_back(sc+1);
                QueenHelper(board, sr+1, ans, result);
                board[sr][sc]=0;    ans.pop_back();
            }
            
        } 
        
}
    
vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> result;     vector<int> ans;
        QueenHelper(board, 0, ans, result);
        return result;
    }

vector<vector<int>> directions = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  //write your code here
  if(upcomingMove==(chess.size()*chess.size())){
      chess[r][c]=upcomingMove;
      display(chess);
      chess[r][c]=0;
      return;
  }

   //Mark the current position as visited with the Move number
   chess[r][c]=upcomingMove;
  
   for(int i=0; i<directions.size(); i++){

      int x=r+directions[i][0];
      int y=c+directions[i][1];

      if(x>=0&&x<chess.size()&&y>=0&&y<chess[0].size()&&chess[x][y]==0){
          printKnightsTour(chess, n, x, y, upcomingMove+1);
      }

    }

    //Unmark the current position after backtracking
    chess[r][c]=0;


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


        // vector<int> arr = {10,20,30,40,50};
        // int target=60;
        // TargetSumSubsets(arr, 0, "", 0, target);


        //vector<vector<int>> board = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
        //NQueens(board, 0, 0, 0, "");
        //GFG
        //display(nQueen(10));

        vector<vector<int>> chess(5, vector<int>(5,0));
        printKnightsTour(chess, 5, 2, 0, 1);


}