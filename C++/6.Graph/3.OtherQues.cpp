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

//Is Graph connected

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


//No. of Island

vector<int> xdir={-1,0,1,0};
vector<int> ydir={0,-1,0,1};

void gccforisland(vector<vector<int>> &graph,int x,int y){
    
    graph[x][y]=1;
    
    for(int d=0; d<4; d++){
        
        int r=x+xdir[d];
        int c=y+ydir[d];
        
        if(r>=0 && r<graph.size() && c>=0 && c<graph[0].size() && graph[r][c]==0)
        gccforisland(graph,r,c);
    }
    
}

int nofIslands(vector<vector<int>> graph){
    
    int count=0;
    
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            if(graph[i][j]==0){
                count++;
                gccforisland(graph,i,j);
            }
        }
    }
    
    return count;
    
}




int main() {
  

}
