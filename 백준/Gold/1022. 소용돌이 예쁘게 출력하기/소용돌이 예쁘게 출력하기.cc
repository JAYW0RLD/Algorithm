#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

int jump_x_p[5005];
int jump_x_n[5005];
int jump_y_p[5005];
int jump_y_n[5005];

int getNumber(int t_r1, int t_c1){
    if(abs(t_r1) < abs(t_c1)){ // x가 더 크면 x축으로 가서 y+- 하자
        if(t_c1 >= 0){ //x 양수일때
            return jump_x_p[abs(t_c1)] - t_r1;// << " ";
        }
        else if(t_c1 < 0){ //x 음수일때
            return jump_x_n[abs(t_c1)] + t_r1;// << " ";
        }
    }
    else if(abs(t_r1) >= abs(t_c1)){ // y가 더 크면 y축으로 가서 x+- 하자
        if(t_r1 >= 0){ //y 양수일때
            return jump_y_p[abs(t_r1)] + t_c1;// << " ";
        }
        else if(t_r1 < 0){ //y 음수일때
            return jump_y_n[abs(t_r1)] - t_c1;// << " ";
        }
    }
    return 0;
}

//에 네 정수 r1, c1, r2, c2가 주어진다.
int main(){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    jump_x_p[0] = 1;
    jump_x_n[0] = 1;
    jump_y_p[0] = 1;
    jump_y_n[0] = 1;
    
    for(int i=1;i<5005;i++){
        jump_x_p[i] = jump_x_p[i-1] + 1 + 8*(i-1);
    }
    for(int i=1;i<5005;i++){
        jump_x_n[i] = jump_x_n[i-1] + 5 + 8*(i-1);
    }
    for(int i=1;i<5005;i++){
        jump_y_p[i] = jump_y_p[i-1] + 7 + 8*(i-1);
    }
    for(int i=1;i<5005;i++){
        jump_y_n[i] = jump_y_n[i-1] + 3 + 8*(i-1);
    }

    //큰 자리수 구하기
    int a1 = getNumber(r1, c1);
    int a2 = getNumber(r1, c2);
    int a3 = getNumber(r2, c1);
    int a4 = getNumber(r2, c2);
    int max_a = max(a1, max(a1, max(a2, a4)));
    // cout << a1<< a2<< a3<< a4 << endl;
    // cout << max_a << endl;
    int n=0;
    while(max_a){
        n++;
        max_a /= 10;
    }
    // cout << n << endl;
    
    for(int t_r1 = r1;t_r1 <= r2;t_r1++){
        for(int t_c1 = c1;t_c1 <= c2;t_c1++){
            cout << fixed << setw(n);
            cout << getNumber(t_r1, t_c1) << " ";
        }
        cout<< endl;
    }
}


