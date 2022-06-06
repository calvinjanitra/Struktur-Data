#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned long long n,k;
    scanf("%llu %llu",&n,&k);
    unsigned long long number[n];

    for(int i =0; i<n; i++){
        scanf("%llu",&number[i]);
    }

    // FIND MAX NUMBER IN EVERY K
    // unsigned long long count = 0;
    unsigned long long max;
    unsigned long long temp = 0;
    unsigned long long stop = k;

    for(int i=0;i<n;i++){
        max = number[i];
        for(int j=i; j< stop; j++){
            if(number[j]>max){
                max = number[j];
            }
        }
        stop++;
        temp += max;
        if(stop > n) break;
    }
    
    printf("%llu",temp);
    return 0;
}