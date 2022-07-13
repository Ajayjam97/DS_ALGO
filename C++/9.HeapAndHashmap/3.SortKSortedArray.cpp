#include <iostream>
#include <queue>
#include <vector>
  
using namespace std;


void PrintKSorted(vector<int> v,int k){

    priority_queue<int, vector<int>, greater<int>> minpq;

    //Add k elements
    for(int i=0; i<k; i++){
        minpq.emplace(v[i]);
    }

    //Process remaining elements
    for(int i=k; i<v.size(); i++){
        //add
        minpq.emplace(v[i]);
        //remove
        cout<<minpq.top()<<endl;
        minpq.pop();
    }

    //Print k elements from priority queue
    while(minpq.size() > 0){
        cout<<minpq.top()<<endl;
        minpq.pop();
    }
}


int main(){

    int n,k;
    cin>>n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
         cin>>v[i];
      }
   
    cin>>k;
    PrintKSorted(v, k);


    return 0;
}