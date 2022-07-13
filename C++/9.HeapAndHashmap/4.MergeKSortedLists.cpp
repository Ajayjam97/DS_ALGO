#include <iostream>
#include <queue>
#include <vector>

using namespace std;

   vector<int> mergeKSortedLists(vector<vector<int>> lists){
      vector<int> rv;

      // write your code here

      return rv;
   }

   int main(){
       
      int k;    cin>>k;
      
      vector<vector<int>> lists;
      
      for(int i = 0; i < k; i++){
         int n; cin>>n;
         vector<int> list(n);
         for(int j = 0; j < n; j++){
            cin>>list[j];
         }

         lists.push_back(list);
      }

      vector<int> mlist = mergeKSortedLists(lists);
      for(int val: mlist){
         cout<<val<<" ";
      }
      cout<<endl;
      
      return 0;
   }

