#include <iostream>
using namespace std;

int filledX[100001];
int N;

int main() {
    cin >> N;

    if(N==3){
        cout << -1;
        exit(0);
    }
    if(N%2==0){
        for(int i=0;i<N;i++){
            cout << (i+2)%N+1 << "\n";
        }
        exit(0);
    }
    if(N%2==1){
        for(int i=0;i<N;i++){
            if(i+1 == N - (i+2)%N){
                cout << (i+3)%N+1 << "\n";
                cout << (i+2)%N+1 << "\n";
                i++;
            }
            else{
                cout << (i+2)%N+1 << "\n";
            }
        }
        exit(0);
    }
    cout << -1;
    
    return 0;
}

// 102001
// 010210
// 001120
// 001102
// 210010
// 120001

// 10201
// 01012
// 00120
// 21010
// 12001

//     1020001
//     0102010
//     0010120
//     0001200
//     0010102
//     2100010
//     1200001

//     000
//     000
//     000