#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> arr[200001];

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int N; cin >> N;
    for(int i=0;i<N;i++){
        pair<int, int> p;
        cin >> p.second >> p.first; //데드라인, 점수
        p.first *= -1;
        arr[i] = p;
    }
    sort(arr, arr+N, cmp); // 데드라인 내림차순 정렬

    priority_queue<pair<int, int>> pq;
    int ans=0;
    for(int i=0;i<N;i++){
        pair<int, int> now = arr[i];
        
        pq.push(now);
        ans += now.first;

        if(pq.size() > now.second){
            ans -= pq.top().first;
            pq.pop();
        }

        // cout << pq.size() << endl;
        // cout << ans << endl;
        // cout << " " << endl;
    }

    cout << ans*-1;
    return 0;
}
