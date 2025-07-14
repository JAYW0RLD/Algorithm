#include <iostream>
#include <math.h>
using namespace std;
double tier[5];

long long facto(int n){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    return ans;
}

double Combi(int n, int i){
    return (double)facto(n)/(facto(n-i)*facto(i));
}

int main() {
    double W,L,D;
    cin >> W >> L >> D;
    for(int i=0;i<=20;i++){ // 승리횟수
        for(int t=0;t<=20-i;t++){
            float draw = 20-i-t;
            int score = 2000 +50*i -50*(t) + 0*draw;

            double prob = Combi(20, i)*pow(W ,i) * Combi(20-i, t)*pow(L, t) *Combi(20-i-t, draw)*pow(D, draw);

            if(1000<= score && score < 1500)
                tier[0] += prob;
            if(1500<= score && score < 2000)
                tier[1] += prob;
            if(2000<= score && score < 2500)
                tier[2] += prob;
            if(2500<= score && score < 3000)
                tier[3] += prob;
            if(3000<= score && score < 3500)
                tier[4] += prob;
        }
    }

    for(int i=0;i<5;i++){
        printf("%.8f\n",tier[i]);
    }
    return 0;
}