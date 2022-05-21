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


//Perfect Friend
void gccforPerfectFriend(vector<vector<int>> graph, int src, vector<bool> &visited, vector<int> &comp){
    
    visited[src]=true;
    comp.push_back(src);
    
    for(int nbr: graph[src]){
        if(!visited[nbr]){
            gccforPerfectFriend(graph, nbr, visited, comp);
        }
    }
    
    
}

int PerfectFriend(vector<vector<int>> graph){
    
    vector<bool> visited(graph.size());
    vector<vector<int>> comps;
    
    for(int i=0; i<graph.size(); i++){
        if(!visited[i]){
            vector<int> comp;
            gccforPerfectFriend(graph, i, visited, comp);
            comps.push_back(comp);
        }
    }
    
    int count=0;

    //method 1 O(N^2)
    // for(int i=0; i<comps.size(); i++){
    //     int size=comps[i].size();
    //     for(int j=i+1; j<comps.size(); j++){
    //         count+=size*comps[j].size();
    //     }
    // }

    //method 2 O(N)
    int sum=comps[comps.size()-1].size();
    for(int i=comps.size()-2; i>=0; i--){
        int s=comps[i].size();
        count+=sum*s;
        sum+=s;
    }

    return count;
}


//Hamiltonian path & cycle
void Hamiltonian(vector<vector<Edge>> graph, int src, int osrc, unordered_set<int> &visited, string psf){
    if(visited.size()==graph.size()-1){
        psf+=to_string(src);
        cout<<psf;
        
        bool iscyclic=false;
        for(Edge e: graph[osrc]){
            if(e.nbr==src){
                iscyclic=true;
                break;
            }
        }
        
        if(iscyclic) cout<<"*"<<endl;
        else cout<<"."<<endl;
        return;
    }
    
    visited.insert(src);
    for(Edge e: graph[src]){
        if(visited.find(e.nbr)==visited.end())
        Hamiltonian(graph, e.nbr, osrc, visited, psf+to_string(src));
    }
    visited.erase(src);
}


//Knights Tour
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vector<int> rdir={-2,-1,1,2,2,1,-1,-2};
vector<int> cdir={1,2,2,1,-1,-2,-2,-1};

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  //write your code here
  
  if(upcomingMove==n*n){
      chess[r][c]=upcomingMove;
      display(chess);
      chess[r][c]=0;
      return;
  }
  
  chess[r][c]=upcomingMove;
  
  for(int dir=0; dir<rdir.size(); dir++){
      int x=r+rdir[dir];
      int y=c+cdir[dir];
      
      if(x>=0 && x<n && y>=0 && y<n && chess[x][y]==0)
      printKnightsTour(chess, n, x, y, upcomingMove+1);
  }
  
  chess[r][c]=0;

}


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
            continue;
        } else{
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




int main() {
  
//   int n,k;
//   cin >> n >> k;
//   vector<vector<int>> graph(n);
  
//   for(int i=0; i<k; i++){
//       int src, nbr;
//       cin>>src>>nbr;    
//       graph[src].push_back(nbr);
//       graph[nbr].push_back(src);
//   }
//   cout<<PerfectFriend(graph);



//   int vtces, edges;
//   cin >> vtces >> edges;
//   vector<vector<Edge>> graph(vtces, vector<Edge>());

//   for (int i = 0; i < edges; i++ ) {
//     int u, v, w;
//     cin >> u >> v >> w;
//     graph[u].push_back(Edge(u, v, w));
//     graph[v].push_back(Edge(v, u, w));
//   }

//   int src; cin >> src;
//   unordered_set<int> visited;
//   Hamiltonian(graph, src, src, visited, "");
  

//vector<vector<int>> chess(5, vector<int>(5,0));
//printKnightsTour(chess,5,2,0,1);



int vtces;  cin >> vtces;
vector<vector<Edge>> graph(vtces, vector<Edge>());
int edges;  cin >> edges;

for (int i = 0; i < edges; i++ ) {
    int u, v, w;    cin >> u >> v >> w;
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
}

int src;  cin >> src;  
BFS(graph, src);

return 0;

}
