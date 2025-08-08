#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct hole{
    int st, end;
};

hole h[10001];

bool cmp(const hole st, const hole end){
    return st.st < end.st;
}

int main() {
    int N,L;
    cin >> N >> L;

    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        h[i].st = a;
        h[i].end = b;
    }

    sort(h, h + N, cmp);

    int cnt=0;
    int useEffectivlyPart = 0;
    for(int i=0;i<N;i++){
        int st = max(h[i].st, useEffectivlyPart);
        int end = h[i].end;
        if(st >= end) continue;
        
        // cout << st << " "<< end << endl;

        int need_cnt = (end - st) / L + 1;
        if((end - st)%L == 0) need_cnt --;
        cnt += need_cnt;
        
        useEffectivlyPart = end + (need_cnt*L - (end - st));
        // cout << useEffectivlyPart-end << endl;
    }

    cout << cnt;
    return 0;
}


