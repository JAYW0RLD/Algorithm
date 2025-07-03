#include <iostream>
#include <map>
#include <climits>
using namespace std;
long long N,P,Q;

map<long long, long long> mem;

// n/P 가 10^11 도 가

long long dp(long long n){
    // cout << "come in" << n << "\n";
    if(mem.count(n) == true)
        return mem[n];
    return mem[n] = dp(n/P) + dp(n/Q);
}

int main() {    
    cin >> N >> P >> Q;

    mem[0] = 1;
    cout << dp(N);
}