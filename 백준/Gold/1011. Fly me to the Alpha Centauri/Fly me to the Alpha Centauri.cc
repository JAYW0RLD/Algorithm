#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int idx=0;idx<n;idx++){
        int q,w; scanf("%d %d",&q,&w);
        int D = w - q;
        if(D == 1 || D == 2 || D == 3){
            printf("%d\n",D);
            continue;
        }
        int ans=0;
        int d;
        d = (int)sqrt(D);
        
        ans += 2*(d-1) + 1;
        int left = D - d*d;
        // printf("D,left %d %d\n",ans,left);
        
        //d^2 + left = D
        for(int i=d;i>=1;i--){
            if(i > left)
                continue;

            ans += left / i;
            left = left % i;
        }

        printf("%d\n",ans);
    }
    return 0;
}