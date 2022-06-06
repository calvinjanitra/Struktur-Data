#include <iostream>
#include <deque>
using namespace std;

int c;
void deq_check(deque<int> deq, int a){
    deque <int> :: iterator it;
    c = 0;
    for(it = deq.begin(); it <= deq.end(); ++it){
        cout << "awal: " << *it << endl;
        if(*it <= a){
            c++;
        }
    }
}

int main()
{
    int n, k, a, e;
    while(1)
    {
        deque<int> d;
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> e;
            d.push_front(e);
            deq_check(d, a);
        }
        if((n - c) <= k) cout << "Bisa boss" << endl;
        else cout << "Gimana nih boss" << endl;
    }
}