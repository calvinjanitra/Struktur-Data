#include <bits/stdc++.h>
#include <iostream>
using namespace std; 

int main(int argc, char const *argv[]){
	vector<int> lubang;
	int n;
	int count;
    int bolaSisa;
	cin >> n;
	int bola[n];
	
	for(int i = 0; i < n; i++){
		count = 2;
		cin>>bola[i];
		
		lubang.push_back(bola[i]);
		for(int j = lubang.size(); j > 0; j--){
			if(bola[i] == lubang[j - 2]){
				if(count == bola[i]){
                    bolaSisa = lubang.size() - count;
                    lubang.resize(bolaSisa);
                    cout<<bolaSisa<<endl;
                    break;
                } 
                count += 1;
			}else{	
				cout<<lubang.size()<<endl;
				break;
			}
		}
	}
	return 0;
	
}