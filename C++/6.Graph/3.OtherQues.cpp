#include<bits/stdc++.h>
using namespace std;


class Edge {
    public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
    }
};


int dfsForisgc(vector<Edge> graph[],int src, int vtces, vector<int> &visited){
    
    int vtcescount=1;
    visited[src]=true;
    for(Edge e: graph[src]){
        int nbr=e.nbr;
        if(!visited[nbr]){
            vtcescount+=dfsForisgc(graph, nbr, vtces, visited);
        }
    }
    
    return vtcescount;
    
}

bool isgc(vector<Edge> graph[], int vtces){
    
    for(int i=0; i<vtces; i++){
        vector<int> visited(vtces,0);
        int vtcescount = dfsForisgc(graph,i,vtces,visited);
        if(vtcescount!=vtces){
            return false;
        }
    }
    
    return true;
}

int main() {
  

}
