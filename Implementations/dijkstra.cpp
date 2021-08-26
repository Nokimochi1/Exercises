#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#define  nl "\n"
#define  ll long long
#define INF 1000000000
using namespace std;
using namespace std;

 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
    public:
        Graph(int V);  // Constructor
 
    // function to add an edge to graph
        void addEdge(int u, int v, int w);
 
    // prints shortest path from s
        void shortestPath(int s);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src, int end)
{
    // Create a set to store vertices that are being
    // processed
    set< pair<int, int> > setds;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //    If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance. 
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
    cout << dist[end]<<nl;
}
 
void solve(){
    int V,K;
    cin>>V>>K;
    Graph g(V);
    while(K--){
        int a,b,c;
        cin>>a>>b>>c;
        g.addEdge(a,b,c);
    }
    cin>>start>>end;
    g.shortestPath(start, end)



}
int main()
{
    int t; cin>>t;
    while (t--){
        solve();
    }
    
 
    return 0;
}