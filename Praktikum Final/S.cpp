#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(int argc, char const *argv[])
{
    ull num;
    set<ull> hacker;
    while(scanf("%llu", &num) != EOF){
        if(hacker.count(num)){
            ull ans = 5001;
            ull x = num % 10001;
			if(x < ans) printf("<\n");
			if(x == ans) printf("==\n");
			if(x > ans) printf(">\n");
        }else hacker.insert(num);
    }
    return 0;
}
