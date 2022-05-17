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

string spath;     int spathwt = INT_MAX;
string lpath;     int lpathwt = INT_MIN;
string cpath;     int cpathwt = INT_MAX;
string fpath;     int fpathwt = INT_MIN;

//priority_queue<pair<int, string>, vector<pair<int, string>> > pq;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;

void multisolver(vector<vector<Edge>> graph, int src, int dst, vector<bool> visited, int criteria, int k, string psf, int wsf){

        if(src == dst) {
            
            psf += to_string(dst);

            //Smallest
            if(wsf<spathwt){
              spath=psf;  spathwt=wsf;
            }

            //Longest
            if(wsf>lpathwt){
              lpath=psf;  lpathwt=wsf;
            }

            //Ceil
            if(wsf>criteria && wsf<cpathwt){
              cpath=psf;  cpathwt=wsf;
            }

            //Floor
            if(wsf<criteria && wsf>fpathwt){
              fpath=psf;  fpathwt=wsf;
            }

            //Kth largest
            if(pq.size()<k){
              pq.push({wsf,psf});
            }
            else{
              if(pq.top().first < wsf){
                pq.pop();
                pq.push({wsf,psf});
              }
            }

            return;
        }

        visited[src] = 1;
        for(Edge e : graph[src]) {
            int nbr = e.nbr;
            int wt = e.wt;
            // if neighbour is unvisited, move toward it
            if(visited[nbr] == 0) {
                multisolver(graph, nbr, dst, visited, criteria, k, psf + to_string(src), wsf + wt);
            }
        }
        visited[src] = 0;

}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {

       vector<int> bfs;
       vector<int> vis(V,0);
       queue<int> q;
       q.push(0);
       vis[0]=1;
       
       while(!q.empty()){
           int node=q.front();
           q.pop();
           bfs.push_back(node);
           
           for(auto it:adj[node]){
               if(!vis[it]){
                   q.push(it);
                   vis[it]=1;
               }
           }
       }

       return bfs;
       
  }

  void dfs(vector<bool> &visited, int src, vector<int> adj[], vector<int> &ans){
        ans.push_back(src);
        visited[src]=1;
        for(int nbr : adj[src]){
            if(!visited[nbr]){
                dfs(visited, nbr, adj, ans);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        vector<int> ans;
        dfs(visited, 0, adj, ans);
        return ans;
        
    }


//Dfs for edge
void dfsForEdge(vector<bool> &visited, int src, vector<Edge> adj[], vector<int> &ans){
        ans.push_back(src);
        visited[src]=1;
        for(Edge e : adj[src]){
            int nbr=e.nbr;
            if(!visited[nbr]){
                dfsForEdge(visited, nbr, adj, ans);
            }
        }
        
}
    
//Get connected components
vector<vector<int>> gcc(vector<Edge> graph[], int vtces){
    
    vector<vector<int>> comps;
    vector<bool> visited(vtces,0);
    
    for(int i=0; i<vtces; i++){
        
        if(!visited[i]){
        vector<int> comp;
        dfsForEdge(visited, i, graph, comp);
        comps.push_back(comp);
        }
        
    }
    
    return comps;
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

  int src,dest;
  cin >> src >> dest;
  vector<bool> visited(vtces,false);

  // if(hasPath(graph, src, dest, visited))
  // cout<<"true";
  // else
  // cout<<"false";


  // printAllPaths(graph, src, dest, visited, "", 0);

  int criteria,k;
  cin >> criteria >> k;

  multisolver(graph, src, dest, visited, criteria, k, src + "", 0);

  cout << "Smallest Path = " << spath << "@" << spathwt << endl;
  cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
  cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
  cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
  cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

}
