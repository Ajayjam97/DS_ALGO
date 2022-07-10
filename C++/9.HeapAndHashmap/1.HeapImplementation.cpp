#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
  
using namespace std;


int main(){

    priority_queue<int> maxheap;
    priority_queue<int, vector<int> ,greater<int>> minheap;

    maxheap.emplace(10);
    maxheap.emplace(30);
    maxheap.emplace(20);
    maxheap.emplace(25);

    cout<<"Top of maxheap: "<<maxheap.top()<<endl;

    minheap.emplace(10);
    minheap.emplace(30);
    minheap.emplace(20);
    minheap.emplace(25);

    cout<<"Top of minheap: "<<minheap.top()<<endl;


    return 0;
}