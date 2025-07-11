#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int two_num=1;
    int used_cup_cnt = 0;
    int ans = 0;
    while(1){
        if(N == 0) break;

        if(used_cup_cnt == K-1){//한컵 남았을 때 여기에 다 담아야해
            while(1){
                if(two_num >= N){
                    break;
                }
                two_num *= 2;
            }
            // cout << "last add " << two_num - N << endl;
            ans += two_num - N;
            break;
        }
        
        if(two_num > N){
            N -= two_num/2;
            two_num = 1;
            used_cup_cnt++;
        }
        else if(two_num == N){
            N -= two_num;
            two_num = 1;
            used_cup_cnt++;
        }
        else{
            two_num *= 2;
        }
    }

    cout << ans;
    return 0;
}
