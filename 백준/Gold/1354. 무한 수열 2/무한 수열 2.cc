#include <iostream>
#include <map>
using namespace std;
long long N, P, Q, X, Y;
map<long long, long long> mem;

long long dp(long long bot){
    if(bot <= 0) return 1;

    if(mem.count(bot) == false)
        mem[bot] = dp(bot/P - X) + dp(bot/Q - Y);
    
    return mem[bot];
}

int main() {
    cin >> N >> P >> Q >> X >> Y;

    cout << dp(N);
    return 0;
}