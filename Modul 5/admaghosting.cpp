#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int banyakGraf, jarakMax = 0;
vector<int> adjList[100];

void dfs(int curVertex, int jarak) {
	if(jarak > jarakMax) jarakMax = jarak;
	// cout<<"jarak max : "<<jarakMax<<endl;
	// cout<<"Vertex 1 : "<<curVertex<<endl;
    for (int i = 0 ; i < adjList[curVertex].size() ; i++){
		// cout<<"Vertex 2 : "<<curVertex<<endl;
		// cout<<"adjlist : "<<adjList[curVertex][i]<<endl;
        int nextVertex = adjList[curVertex][i];
		cout<<endl;
        dfs(nextVertex, jarak+1);
    }
}

int main(){
	int a_node, b_node;
	cin >> banyakGraf;
	int FirstNode[banyakGraf + 1]; 
	memset(FirstNode, 0, sizeof(FirstNode));

	for(int i = 0; i < banyakGraf - 1; i++){
		cin >> a_node >> b_node;
		adjList[a_node].push_back(b_node);
		if(!FirstNode[b_node]){
			// cout<<"First Node : "<<b_node<<endl;
			FirstNode[b_node] = 1;
		}	
	}

	for(int i = 1; i < banyakGraf; i++) 
		if(!FirstNode[i]){
			cout<<endl;
			cout<<"I YANG DICEK : "<<i<<endl;
			dfs(i, 0);
		}
	cout << jarakMax;
	return 0;
}