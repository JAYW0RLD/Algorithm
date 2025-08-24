#include <iostream>
#include <string>
#include <math.h> 
using namespace std;

int main() {
    int N;
    cin >> N;

    string password;
    cin >> password;

    long long total_seconds = 0; 
    int len_p = password.length(); // 비밀번호의 길이

    for (int i = 0; i < len_p; ++i) {
        long long char_diff = password[i] - 'a';

        long long sum_powers_of_26;
        if (N - i > 0) {
            sum_powers_of_26 = (long long)(pow(26, N - i) - 1) / 25;
        } else {
            // N-i가 0인 경우 (즉, 마지막 문자 뒤에는 아무것도 올 수 없음). 26^0 = 1
            sum_powers_of_26 = 1; // 이 경우는 char_diff * 1 이 됨
        }
        
        total_seconds += char_diff * sum_powers_of_26;
        
        // 현재 문자 자체를 찾는 데 걸리는 1초 추가
        total_seconds += 1;
    }

    std::cout << total_seconds << std::endl; // 결과 출력

    return 0;
}