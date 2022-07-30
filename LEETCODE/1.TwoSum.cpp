#include<bits/stdc++.h>
using namespace std;


  vector<int> getrowvector(int r, vector<vector<int>>& grid){
        
        vector<int> result;
        
        for(int i=0; i<grid.size(); i++){
            result.push_back(grid[r][i]);
        }
        
        return result;
    }
    
    
    int findcolumnpair(vector<int> row, vector<vector<int>>& grid){
     
        int r=0; int c=0;
        int result=0;

        
        
        while(c<grid.size()){
            
            cout<<"Hi "<<r<<" "<<c<<" ";

            if(grid[r][c]==row[r]){
                
                cout<<grid[r][c]<<endl;;
                if(r==grid.size()-1){
                    r=0;
                    c++;
                    result++; 
                    break;
                }
                else{
                    r++;
                }
                
            }
            else{
                r=0;
                c++;
            }
        }
        
        cout<<result;
        return result;
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        
        int count=0;
        
      for(int r=0; r<grid.size(); r++){
            
          vector<int> row(grid.size());
          int columnpair;
          
          row = getrowvector(r, grid);
          columnpair = findcolumnpair(row, grid);
          
          count+=columnpair;
          cout<<count<<endl;
          
      }
        
        return count;
    
    }




int main(){

    //  vector<int> nums={3,2,4};  int target=6;
    //  vector<int> result;
    //  unordered_map<int,int> hash;

  
    // for(int i=0; i<nums.size(); i++){
        
    //     if(hash.find(target-nums[i]) != hash.end()){
    //         result.push_back(i);
    //         result.push_back(hash[target-nums[i]]);
    //         break;
    //     }
        
    //     hash[nums[i]]=i;
        
    // }
          
    // for(int indx : result){
    //     cout<<indx<<" ";
    // }


    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout<<equalPairs(grid);

}


