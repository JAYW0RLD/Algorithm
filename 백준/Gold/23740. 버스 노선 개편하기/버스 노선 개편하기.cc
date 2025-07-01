#include <iostream>
#include <algorithm>
using namespace std;

struct Line {
    int st, en, cost;
};

bool cmp(const Line& a, const Line& b) {
    return a.st < b.st;
}

Line lines[200001];
Line merged[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> lines[i].st >> lines[i].en >> lines[i].cost;
    }

    sort(lines, lines + N, cmp);

    int idx = 0;  // merged index
    merged[0] = lines[0];

    for (int i = 1; i < N; i++) {
        // 현재 구간이 이전과 겹치는 경우
        if (lines[i].st <= merged[idx].en) {
            merged[idx].en = max(merged[idx].en, lines[i].en);
            merged[idx].cost = min(merged[idx].cost, lines[i].cost);
        } else {
            // 겹치지 않으면 새로운 구간 추가
            merged[++idx] = lines[i];
        }
    }

    cout << idx + 1 << '\n';
    for (int i = 0; i <= idx; i++) {
        cout << merged[i].st << " " << merged[i].en << " " << merged[i].cost << '\n';
    }

    return 0;
}
