#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#define  nl "\n"
#define  ll long long
using namespace std;



class Graph{
    public:
        map<int,vector<int> > adj;
        map <int, bool> visited;
        
        void addEdge(int u, int v);

        void DFS(int start); 
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFS(int start){
    visited[start] = true;
    cout << start << " ";
    
    for (vector<int>::iterator i = adj[start].begin(); i != adj[start].end(); i++){
        if (!visited[*i]){
            DFS(*i);
        }
    }
}

int main(){
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 1);

    g.DFS(1);
}