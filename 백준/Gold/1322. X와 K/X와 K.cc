#include <iostream>
using namespace std;

int main() {
    unsigned long long X, K;
    cin >> X >> K;

    unsigned long long result = 0;
    unsigned long long bit = 1;

    while (K > 0) {
        // X의 현재 비트가 0인 경우에만 K의 최하위 비트를 결과에 추가
        if ((X & bit) == 0) {
            if (K & 1) {
                result |= bit;
            }
            K >>= 1;
        }
        bit <<= 1;
    }

    cout << result << "\n";
    return 0;
}
