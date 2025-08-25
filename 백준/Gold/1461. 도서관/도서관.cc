#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const int a, const int b){
    return a>b;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        if(input>0) pos.push_back(input);
        if(input<0) neg.push_back(input*-1);
    }

    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);

    int ans=0;
    for (int i = 0; i < pos.size(); i += M) 
        ans += pos[i] * 2;

    for (int i = 0; i < neg.size(); i += M) 
        ans += neg[i] * 2;

    int pos_M = pos.empty() ? 0 : pos[0];
    int neg_M = neg.empty() ? 0 : neg[0];
    ans -= max(pos_M, neg_M);

    cout << ans;
    
    return 0;
}
