#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph {
    int V;

    list<int>* adj;

    void topoSortUtil(int v, bool visited[],stack<int>& myStack);
    
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);

    void addEdge(int v, int w);

    void topoSort();
    
    bool isCyclic(); 
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
   adj[v].push_back(w);
}

void Graph::topoSortUtil(int v, bool visited[],
                                stack<int>& myStack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topoSortUtil(*i, visited, myStack);

    myStack.push(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false; 
    return false;
}
void Graph::topoSort()
{
    stack<int> myStack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topoSortUtil(i, visited, myStack);

    // Print contents of stack
    while (myStack.empty() == false) 
    {
        if (myStack.size() == 1)
            break;
        cout << myStack.top() << " ";
        myStack.pop();
    }
}

bool Graph::isCyclic()
{

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

int main()
{
    int a,b;
    
    cin >> a >> b;
    Graph v(a + 1);
    for(int i = 0; i < a; i++)
    {
        int x,y;
        cin >> x >> y;
        v.addEdge(x, y);
    }
    if(v.isCyclic()){
        cout << "-1" << endl;
    }
    else{
        v.topoSort();
    }
    return 0;
}