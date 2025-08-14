#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree[1001];
int visited[1001];

int dfs(int st,int end,int dist){    
    // cout << "st" << st << endl;
    if(visited[st] == 1)
        return 0;
    
    if(st == end){
        return dist;
    }
    
    visited[st] = 1;

    for(auto &next : tree[st]){
        int ret = dfs(next.first, end, dist+next.second);
        if(ret != 0){
            return ret;
        }
    }

    visited[st] = 0;
    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N-1;i++){
        int st,end,cost;
        cin >> st >> end >> cost;
        tree[st].push_back({end, cost});
        tree[end].push_back({st, cost});
    }
    
    for(int i=0;i<M;i++){
        int st,end;
        cin >> st >> end;

        for(int i=0;i<=N;i++){
            visited[i] = 0;
        }
        
        cout << dfs(st, end, 0) << endl;
    }
    return 0;
}
