#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int dp[100001];
int dp1[100001];

int main() {
    int N; cin >> N;
    int num, arr[100001];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int ans = arr[0];
    dp[0] = arr[0];
    dp[0] = arr[0];
    for(int i=1;i<N;i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]); // 아무것도 안 지운 연속합을 우선 구한다.
        dp1[i] = max(dp[i-1], dp1[i-1]+arr[i]); //순정 연속합에서 분기를 낸다.
        //분기는 이미 지운거에서 순정으로 이어가기 vs 처음 지운 분기로 잡기 

        ans = max({ans, dp[i], dp1[i]});
    }

    // 하나도 안지운 최대 길이
    // 1. 지금을 처음으로 잡는다.arr[i]
    // 3. 지금을 더한다.dp[i-1]+arr[i]

    // 하나를 지운 최대 길이
    // 1. 지금을 더한다 dp[i] + arr[i]
    // 2. 지금을 지운다 dp[i-1].
    cout << ans;
    return 0;
}