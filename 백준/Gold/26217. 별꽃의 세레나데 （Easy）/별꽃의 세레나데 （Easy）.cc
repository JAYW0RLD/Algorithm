#include <iostream>
#include <iomanip> // std::fixed, std::setprecision
using namespace std;

int main() {
    int N; cin >> N;
    
    double ans=0;
    for(int i=0;i<N;i++){
        ans += (double)N/(N-i);
    }
    
    cout << fixed << setprecision(5); // 소숫점 2자리 고정
    cout << ans;
    return 0;
}