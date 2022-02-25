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

//GFG
int matSearch(vector <vector <int>> &mat, int N, int M, int X)
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
        
        
        //BINARY SEARCH O(N*LOG(M))
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


        //BINARY SEARCH O(LOG(M*N))
        //     int lo=0; int hi=(N*M)-1;
        //     while(lo<=hi){
        //         int mid=(lo+(hi-lo)/2);
        //         if(X>mat[mid/M][mid%M]){
        //             lo=mid+1;
        //         }
        //         else if(X<mat[mid/M][mid%M]){
        //             hi=mid-1;
        //         }
        //         else{
        //             return 1;
        //         }
        //     }
        
        // return 0;
        
	}

//LEETCODE
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //BINARY SEARCH O(LOG(M*N))
        int lo=0; int hi=(matrix.size()*matrix[0].size())-1;
            while(lo<=hi){
                int mid=(lo+(hi-lo)/2);
                if(target>matrix[mid/matrix[0].size()][mid%matrix[0].size()]){
                    lo=mid+1;
                }
                else if(target<matrix[mid/matrix[0].size()][mid%matrix[0].size()]){
                    hi=mid-1;
                }
                else{
                    return true;
                }
            }
        
        return false;
    }



vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int rmin=0; int rmax=r-1;
        int cmin=0; int cmax=c-1;
        int count=0;
        
        vector<int> result;
    
        while(count<r*c){
            
            for(int i=cmin; i<=cmax&&count<r*c; i++){
                //cout<<matrix[rmin][i]; 
                result.push_back(matrix[rmin][i]); count++;
            }
            rmin++;
            
            for(int i=rmin; i<=rmax&&count<r*c; i++){
                //cout<<matrix[i][cmax];
                result.push_back(matrix[i][cmax]); count++;
            }
            cmax--;
            
            for(int i=cmax; i>=cmin&&count<r*c; i--){
                //cout<<matrix[rmax][i]; 
                result.push_back(matrix[rmax][i]); count++;
            }
            rmax--;
            
            for(int i=rmax; i>=rmin&&count<r*c; i--){
                //cout<<matrix[i][cmin]; 
                result.push_back(matrix[i][cmin]); count++;
            }
            cmin++;
            
        }
        
        return result;
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

    // vector<vector<int>> v1(2,vector<int>(3));
    // v1 = {
    //     {1,2,3},
    //     {4,5,6}
    // };
    // cout<<matSearch(v1,3,3,5);

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15,16}};
    vector<int> result=spirallyTraverse(matrix,4,4);
    


}