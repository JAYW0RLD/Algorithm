#include <iostream>
#include <unordered_map>
#include <cstdio>  // scanf, printf
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int idx = 0; idx < n; idx++) {
        int Ti;
        scanf("%d", &Ti);

        unordered_map<long long, int> m;
        int max_cnt = -1;
        long long max_id = -1;

        for (int i = 0; i < Ti; i++) {
            long long sol;
            scanf("%lld", &sol);  // long long은 %lld로 받아야 함
            m[sol] += 1;

            if (max_cnt < m[sol]) {
                max_cnt = m[sol];
                max_id = sol;
            }
        }

        if (max_cnt > Ti / 2) {
            printf("%lld\n", max_id);  // 출력도 %lld
        } else {
            printf("SYJKGW\n");
        }
    }

    return 0;
}
