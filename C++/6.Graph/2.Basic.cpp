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


bool hasPath(vector<vector<Edge>> graph, int src, int dest, vector<bool> &visited){  
    if(src==dest) return true;
    
    visited[src]=true; 
    for(Edge e : graph[src]){
        if(!visited[e.nbr]){
            if(hasPath(graph, e.nbr, dest, visited)){
                return true;
            }
        }
    }
    return false;
}



void printAllPaths(vector<vector<Edge>> g, int src, int dst, vector<bool> vis, string psf, int wsf) {
        if(src == dst) {
            psf += to_string(dst);
            cout<<psf<<endl;
            return;
        }

        vis[src] = 1;
        for(Edge e : g[src]) {
            int nbr = e.nbr;
            int wt = e.wt;
            // if neighbour is unvisited, move toward it
            if(vis[nbr] == 0) {
                printAllPaths(g, nbr, dst, vis, psf + to_string(src), wsf + wt);
            }
        }
        vis[src] = 0;
}



int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces);

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here
  
  vector<bool> visited(vtces,false);
    // if(hasPath(graph, src, dest, visited))
    // cout<<"true";
    // else
    // cout<<"false";


    printAllPaths(graph, src, dest, visited, "", 0);

}
