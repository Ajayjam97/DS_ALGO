#include<iostream>
#include<stack>
#include<vector>
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
  

class graph{

public:


    static vector<vector<Edge*>> addEdge(vector<vector<Edge*>> g, int src, int nbr, int wt) {
        g[src].push_back(new Edge(src, nbr, wt));
        g[nbr].push_back(new Edge(nbr, src, wt));
        return g;
    }


    static void display(vector<vector<Edge*>> g) {
        for(int v = 0; v < g.size(); v++) {
            cout<<"["<<v<<"] -> ";
            for(int n = 0; n < g[v].size(); n++) {
                Edge* e = g[v].at(n);
                cout<<"["<<e->src<<"-"<<e->nbr<<" @ "<<e->wt<<"], ";  
            }
            cout<<endl;
        }
    }

 

};


int main(){

        int n = 7;
        vector<vector<Edge*>> g(n);
        for(int i = 0; i < n; i++) {
            g[i].reserve(100);
        }

        //g = graph::addEdge(g, 0, 1, 10);
        //g = graph::addEdge(g, 0, 3, 40);
        //g = graph::addEdge(g, 1, 2, 10);
        //g = graph::addEdge(g, 2, 3, 10);
        //g = graph::addEdge(g, 3, 4, 2);
        //g = graph::addEdge(g, 4, 5, 3);
        //g = graph::addEdge(g, 4, 6, 8);
        //g = graph::addEdge(g, 5, 6, 3);
        //graph::display(g);




        //Easy method to make a graph without using class

        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<=n; i++){
            int u,v,wt;
            cin>>u>>v>>wt;

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        for(int i=0; i<=n; i++){
            for(int j=0; j<adj[i].size(); j++)
            cout<<i<<"->"<<adj[i][j].first<<" @ "<<adj[i][j].second<<endl;
        }

}