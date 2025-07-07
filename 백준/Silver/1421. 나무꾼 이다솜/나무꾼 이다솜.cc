#include <iostream>
#include <iostream>
using namespace std;
int N, C, W;
int arr[51];


long long get_cost(long long len){
    long long money = 0;
    for(int i=0;i<N;i++){
        long long cut_cnt = arr[i]/len;
        if(cut_cnt == 0 && arr[i] % len != 0) continue;
        
        if(cut_cnt != 0 && arr[i] % len == 0) cut_cnt --;

        long long sell_len = arr[i] - arr[i]%len;
        if(sell_len*W - cut_cnt*C<0) continue;
        
        money += sell_len*W - cut_cnt*C;
    }
    return money;
}

int main() {
    cin >> N >> C >> W;
    int max_n = -1;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        max_n = max(max_n, arr[i]);
    }

    long long ans = 0;
    for(int i=1;i<=max_n;i++){
        ans = max(ans, get_cost(i));
    }
    cout << ans;
}
