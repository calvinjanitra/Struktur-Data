#include <bits/stdc++.h>
using namespace std;

typedef struct isi{
    double total;
    vector<int> index;
    map<int, int> banyak;
} data;

vector<data> stats(107);
map<int, int>::iterator it;
int n, m, q, x, y, a, maks = 0, in = 0;
string str;

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        data *dat = &stats[i]; 
        dat->total = 0; 
        dat->index.assign(a, 0); 
        
        for(int j = 0; j < a; j++)
        {
            cin >> m;
            dat->total += m;
            dat->index[j] = m; 
            dat->banyak[m]++; 
        }
    }
    while(q--){
        cin >> str;
        if(str=="tambah")
        {
            cin >> x >> y;
            data *dat = &stats[y];
            dat->total += x;
            dat->index.push_back(x);
            dat->banyak[x]++;
        }
        else if(str=="hilang")
        {
            cin >> x >> y;
            data *dat = &stats[y];
            dat->total -= dat->index[x - 1];
            dat->banyak[dat->index[x - 1]]--;
            dat->index.erase(dat->index.begin() + x - 1);
        }
        else if(str=="tukar")
        {
            cin >> x >> y;
            swap(stats[x], stats[y]);
        }
        else if(str=="b_atas")
        {
            cin >> x >> y;
            data dat = stats[y];
            vector<int> g = dat.index;
            sort(g.begin(), g.end());
            vector<int>::iterator hi = upper_bound(g.begin(), g.end(), g[x - 1]);
            cout << hi - g.begin() << endl;
        }
        else if(str=="b_bawah")
        {
            cin >> x >> y;
            data dat = stats[y];
            vector<int> g = dat.index;
            sort(g.begin(), g.end());
            vector<int>::iterator lo = lower_bound(g.begin(), g.end(), g[x - 1]);
            cout << lo - g.begin() + 1 << endl;
        }
        else if(str=="banyak")
        {
            cin >> x;
            data dat = stats[x];
            cout << dat.index.size() << endl;
        }
        else if(str=="mean")
        {
            cin >> x;
            data dat = stats[x];
            cout << dat.total / dat.index.size() << endl;
        }
        else if(str=="median")
        {
            cin >> x;
            data dat = stats[x];
            vector<int> g = dat.index;
            int size_t = g.size();
            sort(g.begin(),g.end());
            double rata = g[size_t / 2] + g[size_t / 2 - 1]; 
            if(size_t % 2)
                cout << g[size_t / 2] << endl;
            else{
                cout << (rata / 2) << endl;
            }
        }
        else if(str=="modus")
        {
            cin >> x;
            data dat = stats[x];
            for(it = dat.banyak.begin(); it != dat.banyak.end(); it++)
            {
                if(it->second > maks)
                {
                    maks = it->second;
                    in = it->first;
                }
                else if(it->second == maks && it->first > in)
                    in = it->first;
            }
            cout << in << endl;
        }
        else if(str=="urut")
        {
            cin >> x;
            vector<int> g = stats[x].index;
            sort(g.begin(), g.end());
            for(long unsigned int i = 0; i < g.size(); i++)
                cout << g[i] << " ";
            cout << endl;
        }
        else cout << "Query not found" << endl;
        }

    return false;
}