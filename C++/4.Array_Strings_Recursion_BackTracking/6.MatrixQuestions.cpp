#include <bits/stdc++.h>
using namespace std;  

void MatrixMultiplication(vector<vector<int>> v1, vector<vector<int>> v2){

    if(v1[0].size()!=v2.size()){
          cout<<"Invalid input"<<endl;
          return;
    }

    vector<vector<int>> result(v1.size(),vector<int>(v2[0].size()));

    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2[0].size(); j++){
            int ans=0;
            for(int k=0; k<v2.size(); k++){
                ans+=v1[i][k]*v2[k][j];
            }
            result[i][j] = ans;       
        }
    }


    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    
	    //BRUTE FORCE O(N*M)
	    // for(int i=0; i<N; i++){
        //         for(int j=0; j<M; j++){
        //             if(mat[i][j]==X){
        //                 return 1;
        //             }
        //         }
        //     }      
        //     return 0;
        
        
        //BINEARY SEARCH O(N*LOG(M))
            int row=0; int column=M-1;
            while(row<N && column>=0){ 
                if(X>mat[row][column]){
                    row++;
                }
                else if(X<mat[row][column]){
                    column--;
                }
                else{
                    return 1;
                }
            }
        return 0;
        
	}

int main(){

    // vector<vector<int>> v1(2,vector<int>(3));
    // v1 = {
    //     {1,2,3},
    //     {4,5,6}
    // };
    // vector<vector<int>> v2(3,vector<int>(2));
    // v2 = {
    //     {1,2},
    //     {1,2},
    //     {1,2},
    // };
    // MatrixMultiplication(v1,v2);

    vector<vector<int>> v1(2,vector<int>(3));
    v1 = {
        {1,2,3},
        {4,5,6}
    };
    cout<<matSearch(v1,3,3,5);



}