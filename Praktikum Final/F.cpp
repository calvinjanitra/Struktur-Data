#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> twoPair;
class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<twoPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src){
    priority_queue<twoPair, vector<twoPair>, greater<twoPair>> pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }   
        }
    }
    for (int i = 1; i < V; i++){
        cout << i;
        cout << " " << dist[i];
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int vertex, edge, weight;
    int vertex1;
    int vertex2;
    cin>>vertex;
    cin>>edge;
    Graph graf(vertex);
    
    for (int i = 0; i < edge; i++){
        cin>>vertex1;
        cin>>vertex2;
        cin>>weight;
        graf.addEdge(vertex1, vertex2, weight);
    }
    graf.shortestPath(0);  
    return 0;
}