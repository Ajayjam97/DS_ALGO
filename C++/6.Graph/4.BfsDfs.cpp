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

//BFS
void BFS(vector<vector<Edge>> graph, int src){
    
    queue<pair<int,string>> qu;
    qu.push({src,""});
    vector<bool> visited(graph.size());

    while(qu.size() > 0){
        //1. Get + Remove
        pair<int,string> rem=qu.front(); qu.pop();

        //2. Mark *
        if(visited[rem.first]==true){
            //Already visited -> continue
            continue;
        } else{
            //Unvisited -> Mark as visited
            visited[rem.first]=true;
        }

        //3. Work -> Print
        cout<<rem.first<<"@"<<rem.second<<to_string(rem.first)<<endl;

        //4. Add unvisited neighbours
        for(Edge e: graph[rem.first]){
            if(visited[e.nbr]==false){
                qu.push({e.nbr, rem.second+to_string(rem.first)});
            }
        }
        
    }
}

//DFS
void DFS(vector<bool> &visited, int src, vector<Edge> adj[], vector<int> &ans){
        ans.push_back(src);
        visited[src]=1;
        for(Edge e : adj[src]){
            int nbr=e.nbr;
            if(!visited[nbr]){
                DFS(visited, nbr, adj, ans);
            }
        }
        
}


//Is Cyclic Undirected graph
bool BfsForCycle(int src, vector<vector<Edge>> graph, vector<bool> & visited){
    
    queue<int> qu;
    qu.push(src);

    while(qu.size() > 0){
        //1. Get + Remove
        int rem=qu.front(); qu.pop();

        //2. Mark *
        if(visited[rem]==true){
            //Already visited, Therefore Cycle found -> return true
            return true;;
        } else{
            //Unvisited -> Mark as visited
            visited[rem]=true;
        }

        //4. Add unvisited neighbours
        for(Edge e: graph[rem]){
            if(visited[e.nbr]==false){
                qu.push(e.nbr);
            }
        }
        
    }

    return false;
    
}

bool DfsForCycle(int src, int par, vector<vector<Edge>> graph, vector<bool> & visited){

    visited[src]=true;

    for(Edge e: graph[src]){
        if(!visited[e.nbr]){
            DfsForCycle(e.nbr, src, graph, visited);
        }
        else if(e.nbr!=par && visited[e.nbr]){
            return true;
        }
    }

    return false;
}

bool IsCyclic(vector<vector<Edge>> graph, int vtces){
    
    vector<bool> visited(vtces,0); 
    for(int i=0; i<vtces; i++){
        if(!visited[i]){
            //if(BfsForCycle(i,graph,visited)){
            if(DfsForCycle(i,-1,graph,visited)){
                return true;
            }
        }
    }
    
    return false;
}







int main() {

int vtces;  cin >> vtces;
vector<vector<Edge>> graph(vtces, vector<Edge>());
int edges;  cin >> edges;

for (int i = 0; i < edges; i++ ) {
    int u, v, w;    cin >> u >> v >> w;
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
}

//int src;  cin >> src;  
//BFS(graph, src);

 if(IsCyclic(graph, vtces)){
     cout<<"true"<<endl;
 }
 else{
     cout<<"false"<<endl;
 }


return 0;

}
