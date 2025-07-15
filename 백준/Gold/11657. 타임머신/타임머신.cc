#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<long long,long long,long long>> edges;
long long cost_min[501];
long long INF = 20000000000;

int main() {
    long long N, M;
    cin >> N >> M;
    for(long long i=0;i<M;i++){
        long long A,B,C;
        cin >> A >> B >> C;

        edges.push_back({A,B,C});
    }
    for(long long i=1;i<=N;i++){
        cost_min[i] = INF;
    }
    
    cost_min[1] = 0;
    for(long long i=0;i<N-1;i++){
        for(auto [u,v,w]: edges){
            if(cost_min[u]!=INF&& cost_min[v] > cost_min[u]+w){
                cost_min[v] = cost_min[u]+w;
            }
        }
    }

    for(auto [u,v,w]: edges){
        if(cost_min[u]!=INF && cost_min[v] > cost_min[u]+w){
            cout << "-1\n";
            return 0;
        }      
    }

    for(long long i=2;i<=N;i++){
        if(cost_min[i] != INF)
            cout << cost_min[i] << endl;
        else
            cout << "-1\n";
    }
    
    return 0;
}


