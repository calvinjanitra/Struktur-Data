#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    int n,m;
    int u,v;
    vector < vector<int> > adjList(m+1, vector<int>());
    int visited[n+1];
    
    for(int i= 0; i<t; i++){
        cin>>n>>m;
        for(int j=0;j<m;j++){
            cin>>u>>v;
            adjList[u].push_back(v);
        }
    }

    return 0;
}
