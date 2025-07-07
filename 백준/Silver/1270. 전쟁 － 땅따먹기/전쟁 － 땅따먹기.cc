#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for(int idx=0;idx<n;idx++){
        int Ti; cin >> Ti;

        map<long long,int> m;
        int max=-1;
        long long max_i=-1;
        for(int i=0;i<Ti;i++){
            long long sol;
            cin >> sol;
            m[sol] += 1;
            if(max < m[sol]){
                max = m[sol];
                max_i = sol;
            }
        }

        if(max > Ti/2){
            cout << max_i << "\n";
        }
        else{
            cout << "SYJKGW\n";
        }
    }
    return 0;
}