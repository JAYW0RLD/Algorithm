#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N,M,D;
    
    vector<vector<int>> arr;
    vector<vector<int>> mem;
    
    cin >> N >> M >> D;
    
    arr = vector<vector<int>>(N, vector<int>(M, INT_MIN));
    mem = vector<vector<int>>(N, vector<int>(M, INT_MIN));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    for(int j=0;j<M;j++){
        mem[0][j] = 0;
    }
    
    for(int Y=0;Y<N;Y++){
        for(int X=0;X<M;X++){    
            for(int dy=1; dy <= D; dy++){
                for(int dx=-(D-dy); dx<=(D-dy); dx++){
                    if(Y+dy < 0 || Y+dy >= N || X+dx<0 || X+dx>=M) continue;
                    if(mem[Y+dy][X+dx] > mem[Y][X] + arr[Y][X]*arr[Y+dy][X+dx]) continue;
                    
                    mem[Y  + dy][X + dx] = mem[Y][X] + arr[Y][X]*arr[Y +dy][X+dx];
                }
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << mem[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int ans=INT_MIN;
    for(int j=0;j<M;j++){
        ans = max(ans, mem[N-1][j]);
    }
    
    cout << ans;

    return 0;
}