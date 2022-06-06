#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	deque<ll> deq;
	int n, b;
	cin >> n >> b;
	
	for(int i = 0; i < n; ++i)
	{
		ll t, d;
		cin >> t >> d;
		if(i) cout << " ";
		
		while(!deq.empty() and deq.front() <= t)
			deq.pop_front();
		
		if(!deq.size()){
			deq.push_back(t + d);
			cout << t + d;
		}
		else if(deq.size() <= b)
		{
			ll bk = deq.back();
			deq.push_back(bk + d);
			cout << bk + d;
		}
		else cout << -1;
	}
	cout << endl;
	return 0;
}