#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int arr[51];
vector<int> child[51];
int dp[51];
int N;

int dfs(int now){
    vector<int> child_times;
    for(int i=0;i<child[now].size();i++){
        child_times.push_back(dfs(child[now].at(i)));
    }

    sort(child_times.rbegin(), child_times.rend());

    int total=0;
    for(int i=1;i<=child_times.size();i++){
        total = max(total, child_times[i-1]+i);
    }

    return total;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i]; // i 번째 노드의 입력값
        if(arr[i]==-1) continue;
        child[arr[i]].push_back(i);
    }

    cout << dfs(0);
    
    return 0;
}