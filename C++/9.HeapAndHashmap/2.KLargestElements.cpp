#include <iostream>
#include <queue>
#include <vector>
  
using namespace std;


void PrintKElements(vector<int> v,int k){

    priority_queue<int, vector<int>, greater<int>> pq;

    //Add k elements
    for(int i=0; i<k; i++){
        pq.emplace(v[i]);
    }
    //Process remaining elements
    for(int i=k; i<v.size(); i++){
        if(v[i] > pq.top()){
            pq.pop();
            pq.emplace(v[i]);
        }
    }

    //Print k elements from priority queue
    while(pq.size() > 0){
        cout<<pq.top()<<endl;
        pq.pop();
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
    PrintKElements(v, k);


    return 0;
}