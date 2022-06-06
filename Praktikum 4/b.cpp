#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> v;
int visited[1001];

void  DFS(int u){
    for(auto i : v[u]){
        visited[u] = true;
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    v.assign(n + 1, vector<int>());
    visited[n] = false;
    int count = 0;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count++;
            DFS(i);
        }
    }
    // cout<<"Count : "<<count<<endl;
    cout << m - n + count << endl;
}