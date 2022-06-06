#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <bits/stdc++.h>
#define pb push_back
int path, sum = 0;
using namespace std;

vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
    g[a].pb(b);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    v[u] = true;

    while (!q.empty()) {

        int f = q.front();
        q.pop();
        path = 0;

        // Enqueue all adjacent of f and mark them visited
        for (int i = 0; i < g[f].size(); i++) {
            int next = g[f][i];
            if (!v[next]) {
                //cout << "next " << next << endl; 
                path++;
                q.push(next);
                v[next] = true;
            }
        }
        int s = 1, c = path;
        while(s < c + 1){
            s *= 2;
            path++;
        }

        sum += path;
    }
}

// Driver code
int main()
{
    int n;
    cin >> n;
    
    v.assign(n + 1, false);
    g.assign(n + 1, vector<int>());
    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        edge(a, b);
    }
    for(int i = 1; i <= n; i++){
        if(!v[i]) bfs(i);
    }
    cout << sum << endl;
    return 0;
}
