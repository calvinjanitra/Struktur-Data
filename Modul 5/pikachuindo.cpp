#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int map[11][11];
bool visited[11][11];
void f(int x, int y){
    if(x >= 0 && y >= 0 && x < 10 && y < 10){
        if(!visited[x][y]){
            if(map[x][y] == 1){
                map[x][y] = 0;
                visited[x][y] = true;
                f(x + 1, y);
                f(x - 1, y);
                f(x, y + 1);
                f(x, y - 1);
            }
        }
    }
}

int main() {
    int c = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(map[i][j] && !visited[i][j]){
                f(i, j);
                ++c;
            }
        }
    }
    cout << c << endl;
}
