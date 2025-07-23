#include <iostream>
using namespace std;

int S[50];
int P[50];
int P_init[50];
int P_tmp[50];
int N;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> P[i];
        P_init[i] = P[i];
    }
    for(int i=0;i<N;i++){
        cin >> S[i];
    }

    int isComplete,isPSameWithInit,iterCnt=0;
    while(1){
        isComplete=1;
        isPSameWithInit=0;
        //조건 맞는지 검사
        for(int i=0;i<N;i++){
            if((i%3 == 0 && P[i]!=0) ||
                (i%3 == 1 && P[i]!=1) ||
                (i%3 == 2 && P[i]!=2)){
                isComplete = 0;
                break;
            }
        }
        if(isComplete==1){
            break;
        }

        //셔플
        for(int i=0;i<N;i++){
            P_tmp[S[i]] = P[i];
        }
        for(int i=0;i<N;i++){
            P[i] = P_tmp[i];
        }

        //초기값 검사
        isPSameWithInit = 1;
        for(int i=0;i<N;i++){
            if(P[i] != P_init[i]){
                isPSameWithInit=0;
                break;
            }
        }
        if(isPSameWithInit==1){
            break;
        }
        
        iterCnt++;
    }

    if(isPSameWithInit==1){
        cout << -1;
        return 0;
    }
    
    cout << iterCnt;
    return 0;
}