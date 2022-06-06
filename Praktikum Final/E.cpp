#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	int n;
	int res = INT_MAX;
	bool check;
	
	cin >> n;
	pair<int, int> xy[n];
	
	for(int i = 0; i < n; ++i){
		cin >> xy[i].first >> xy[i].second;
	}
	
	for(int i = 0; i < n - 2; ++i){
		for(int j = i + 1; j < n - 1; ++j){
			for(int k = j + 1; k < n; ++k){
				int x1 = xy[i].first * xy[j].second;
				int x2 = xy[i].second * xy[k].first;
				int x3 = xy[j].first * xy[k].second;
				int y1 = xy[i].second * xy[j].first;
				int y2 = xy[i].first * xy[k].second;
				int y3 = xy[j].second * xy[k].first;	
				
				int temp = abs(x1+x2+x3-y1-y2-y3);
				
				if(temp > 0 && temp < res){
					res = temp; 
					check = true;
				}else if(temp == res) check = false;
			}
		}
	}
	if(check && res != INT_MAX){
		if(res % 2 == 0){
            cout << res / 2 << ".00" << endl;
        }else{
            cout << res / 2 << ".50" << endl;
        } 
	}else{
        cout << "-1.00" << endl;
    } 
	return 0;
}