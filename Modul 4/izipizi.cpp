#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMax(vector <int>& a){
    return *max_element(a.begin(), a.end());
}

int main(int argc, char const *argv[]){
    vector <int> a;

    int n;
    cin>>n;

    if(n == 0){
        cout<<"Oiya lupa gapunya kambing, hehe";
        return 0;
    }

    int w;
    for(int i = 0; i < n; i++){
        cin>>w;
        a.push_back(w);
    }
    int res = findMax(a);
    cout<<res<<endl;
    // res = max_element(a.begin(), a.end());
    return 0;
}
