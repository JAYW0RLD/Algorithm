#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long net_arr[1000000];//index 가 0 = min, max-min = max

int main(){
    long long min,max;
    cin >> min >> max;

    int cnt=0;
    for(long long i=2; i*i<=max; i++){
        long long start = min + (i*i - min % (i*i));
        if(min % (i*i) == 0) start -= i*i;
        
        for(long long j=start; j <= max ;j += i*i){
            net_arr[j-min] = 1;
        }
    }

    for(long long i=0;i<max-min+1;i++){
        if(net_arr[i] == 0) cnt ++;
    }

    cout << cnt;

}