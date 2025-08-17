#include <iostream>
using namespace std;
int color[4];
long long fact[11];

void build_fact() {
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) fact[i] = fact[i-1] * i;
}

long long ways_two_colors(int k) {              // k 짝수 가정
    int half = k / 2;
    return fact[k] / (fact[half] * fact[half]); // C(k, k/2)
}

long long ways_three_colors(int k) {            // k 3의 배수 가정
    int t = k / 3;
    return fact[k] / (fact[t] * fact[t] * fact[t]); // k! / (t!)^3
}

long long dfs(int N,int *color){
    if(N<=0) return 1;
    
    long long ans =0;
    for(int i=1;i<=3;i++){
        //카드 하나만 쓸 때 
        if(color[i] >= N){
            color[i] -= N;
            // cout <<"N에서 " <<N<< i << "하나만 쓸게"<<endl;
            ans += dfs(N-1, color);
            color[i] += N;
        } 
    }
    
    //카드 두개 쓸 때
    if(N%2==0){
        if(color[1]>=N/2 && color[2]>=N/2){
            color[2] -= N/2;
            color[1] -= N/2;
            ans += dfs(N-1, color)* ways_two_colors(N);
            color[1] += N/2;
            color[2] += N/2;
        }
        if(color[1]>=N/2 && color[3]>=N/2){
            color[1] -= N/2;
            color[3] -= N/2;
            ans += dfs(N-1, color)* ways_two_colors(N);
            color[3] += N/2;
            color[1] += N/2;
        }
        if(color[3]>=N/2 && color[2]>=N/2){
            color[3] -= N/2;
            color[2] -= N/2;
            ans += dfs(N-1, color)* ways_two_colors(N);
            color[2] += N/2;
            color[3] += N/2;
        }
    }

    if(N%3==0 && color[1]>=N/3&& color[2]>=N/3&& color[3]>=N/3){
        color[1] -= N/3;
        color[2] -= N/3;
        color[3] -= N/3;
        ans += dfs(N-1, color)* ways_three_colors(N);
        color[1] += N/3;
        color[2] += N/3;
        color[3] += N/3;
    }
    return ans;
}

int main() {
    int N,r,g,b;
    cin >> N >> color[1] >> color[2] >> color[3];
    build_fact();
    
    cout << dfs(N, color);
    return 0;
}

// 1
// 2/1 1
// 3/1 1 1
// 4/2 2
// 5
// 6/2 2 2/3 3
// 7
// 8/4 4
// 9/3 3 3
// 10