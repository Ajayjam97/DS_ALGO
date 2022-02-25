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

//LEETCODE
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>> result;
        
        for(int i=0; i<matrix[0].size(); i++){
            vector<int> temp;
            for(int j=0; j<matrix.size(); j++){
                temp.push_back(matrix[j][i]);
            }
            result.push_back(temp);
        }
        
        return result;
    }

//LEETCODE
void rotate(vector<vector<int>>& matrix) {
        
        matrix = transpose(matrix);
        
        for(int i=0; i<matrix.size(); i++){
            
            int lo=0; int hi=matrix[0].size()-1;
            
            while(lo<hi){
                int temp=matrix[i][lo];
                matrix[i][lo++]=matrix[i][hi];
                matrix[i][hi--]=temp;
            }
        }
        
        
    }

//GFG
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

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    pair<int,int> p;
	    p.first = -1; //Row index
        p.second = 0; //Number of 1s 
	    
	    for(int i=0; i<n; i++){
	        
	        int col=m-1;
	        int rowcount=0;

	        while(arr[i][col]==1){
	            col--;
                rowcount++;
	        }

            if(rowcount>p.second){
                p.second=rowcount; p.first=i;
            }
	    }

        return p.first;
}

//LEETCODE
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int> result;
        
        for(int row=0; row<matrix.size(); row++){
            
            //Find index of the minimum value in current row
            int MinColIndex=0;
            for(int col=1; col<matrix[0].size(); col++){
                if(matrix[row][col]<matrix[row][MinColIndex]){
                    MinColIndex=col;
                }
            }
            
            //Assume current element at matrix[row][MinColIndex] to be the saddle point.
            //If the value in other rows at the same column is greater than this point then it is not a saddle point.
            bool saddlepoint = true;
            for(int Mrow=0; Mrow<matrix.size(); Mrow++){
                if(matrix[Mrow][MinColIndex]>matrix[row][MinColIndex]){
                    saddlepoint=false;
                    break;
                }
            }
            
            if(saddlepoint==true){
                result.push_back(matrix[row][MinColIndex]);
            }
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

    // vector<vector<int>> matrix = {{1, 2, 3, 4},
    //                               {5, 6, 7, 8},
    //                               {9, 10, 11, 12},
    //                               {13, 14, 15,16}};

    // matrix = transpose(matrix);
    // for(int i=0; i<matrix.size(); i++){
    //     for(int j=0; j<matrix[0].size(); j++) cout<<matrix[i][j]<<" ";
    //     cout<<endl;
    // }

    // rotate(matrix);
    // for(int i=0; i<matrix.size(); i++){
    //     for(int j=0; j<matrix[0].size(); j++) cout<<matrix[i][j]<<" ";
    //     cout<<endl;
    // }

    //vector<int> result=spirallyTraverse(matrix,4,4);

    vector<vector<int>> arr = {{0, 0}, {0, 0}};
    cout<<rowWithMax1s(arr,2,2);
    


}