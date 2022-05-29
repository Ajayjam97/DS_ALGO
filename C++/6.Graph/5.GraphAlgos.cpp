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



//Dijkastra

void Dijkastra(vector<vector<Edge>> graph, int src){
    
    //Min Priority Queue
    priority_queue< pair<int, pair<int , string>>, vector<pair<int, pair<int , string>>>, greater<pair<int, pair<int , string>>> > qu;
    //first = wsf, second.first = src, second.second = psf

    qu.push({0, {src,""+to_string(src)}}); 
    vector<bool> visited(graph.size());

    while(qu.size() > 0){
        //1. Get + Remove
        pair<int, pair<int, string>> rem=qu.top(); qu.pop();

        //2. Mark *
        if(visited[rem.second.first]==true){
            //Already visited -> continue
            continue;
        }
        //Unvisited -> Mark as visited
        visited[rem.second.first]=true;

        //3. Work -> Print
        cout<<rem.second.first<<" via "<<rem.second.second<<" @ "<<rem.first<<endl;

        //4. Add unvisited neighbours
        for(Edge e: graph[rem.second.first]){
            if(visited[e.nbr]==false){
                qu.push({rem.first+e.wt, {e.nbr, rem.second.second+to_string(e.nbr)}});        
            }
        }
        
    }
}


//Minimum Spanning tree
//MST implementation using Prims algorithm
void Prims(vector<vector<Edge>> graph, int src){
    
    //Min Priority Queue
    priority_queue< pair<int, pair<int , int>>, vector<pair<int, pair<int , int>>>, greater<pair<int, pair<int , int>>> > qu;
    //first = wt, second.first = src, second.second = parent

    qu.push({0, {0, -1}}); 
    vector<bool> visited(graph.size());

    while(qu.size() > 0){
        //1. Get + Remove
        pair<int, pair<int, int>> rem=qu.top(); qu.pop();

        //2. Mark *
        if(visited[rem.second.first]==true){
            //Already visited -> continue
            continue;
        }
        //Unvisited -> Mark as visited
        visited[rem.second.first]=true;

        //3. Work -> Print
        if(rem.second.second!=-1)
        cout<<"["<<rem.second.first<<"-"<< rem.second.second <<"@"<<rem.first<<"]"<<endl;

        //4. Add unvisited neighbours
        for(Edge e: graph[rem.second.first]){
            if(visited[e.nbr]==false){
                qu.push({e.wt, {e.nbr, rem.second.first}});        
            }
        }
        
    }
}




//Topological Sort



int main() {

vector<vector<Edge>> graph(7, vector<Edge>());

graph[0].push_back(Edge(0,1,10));
graph[1].push_back(Edge(1,0,10));
graph[1].push_back(Edge(1,2,10));
graph[2].push_back(Edge(2,1,10));
graph[2].push_back(Edge(2,3,10));
graph[3].push_back(Edge(3,2,10));
graph[0].push_back(Edge(0,3,40));
graph[3].push_back(Edge(3,0,40));
graph[3].push_back(Edge(3,4,2));
graph[4].push_back(Edge(4,3,2));
graph[4].push_back(Edge(4,5,3));
graph[5].push_back(Edge(5,4,3));
graph[5].push_back(Edge(5,6,3));
graph[6].push_back(Edge(6,5,3));
graph[4].push_back(Edge(4,6,8));
graph[6].push_back(Edge(6,4,8));
graph[2].push_back(Edge(2,5,5));
graph[5].push_back(Edge(5,2,5));




Dijkastra(graph, 0);



return 0;

}
