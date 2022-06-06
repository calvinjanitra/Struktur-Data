#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, bool visited[],stack<int>& Stack);
    
bool isCyclicUtil(int v, bool visited[], bool *rs);