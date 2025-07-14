#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int X,Y,D,T;
    cin >> X >> Y >> D >> T;

    double distance = sqrt(1.0 * X * X + 1.0 * Y * Y);
    
    if(T >= D){
        printf("%.12lf", distance);
        return 0;
    }

    int jump_cnt=0;
    while(1){
        if(distance < 0){
            break;
        }

        distance -= D;
        jump_cnt += 1;
    }
    //일단 distance는 넘어간 직후
    
    // 1. 넘어가기 전에 걷기
    double before_cross_time = (jump_cnt-1)*T + (distance+D)*1;
    
    // 2. 넘어가서 걷기-> 삐뚤게 뛰기
    double after_cross_time = jump_cnt*T;
    if(jump_cnt == 1){
        after_cross_time += min(double(T), distance * -1.0);
    }
    
    printf("%.12lf", min(before_cross_time, after_cross_time));
    return 0;
}