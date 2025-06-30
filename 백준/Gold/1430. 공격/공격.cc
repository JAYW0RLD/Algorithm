#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <queue>
#include <math.h>
using namespace std;

float getDistance(int y1, int x1, int y2, int x2){
    return pow(pow(y1-y2, 2) + pow(x1-x2, 2), 1.0/2.0);
}

struct point {
    int x;
    int y;
    float D;
};

int px[51];
int py[51];
int visited[51];

//탑의 개수 N, 사정 거리 R, 초기 에너지 D, 적의 X좌표 X, 적의 Y좌표 Y가 주어진다. 둘째 줄부터는 탑의 위치가 한 줄에 하나씩 X좌표 Y좌표 순으로
int main(){
    int N, R, D, enemyX, enemyY;
    cin >> N >> R >> D >> enemyX >> enemyY;

    for(int i=0;i<N;i++){
        int x,y,d;
        cin >> x >> y;
        px[i]=x;
        py[i]=y;
    }

    float ans_D = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<51;j++){
            visited[j] = 0;
        }
        point p;
        p.x = px[i];
        p.y = py[i];
        p.D = D;
        // cout << "시작 " << px[i] << " " << py[i] << endl;

        queue<point> q;
        q.push(p);
        visited[i] = 1;

        float maxD = 0;
        while(!q.empty()){
            point now_point = q.front();
            // cout << "접근 " << now_point.x << " " << now_point.y << " " << now_point.D << endl;
            if(maxD < now_point.D 
                && getDistance(now_point.x,now_point.y,enemyX,enemyY) <= R){
                maxD = now_point.D;
                // cout << "찾음" << endl;
                continue;
            }

            for(int j=0;j<N;j++){
                if(visited[j]) continue;
                point target_point;
                target_point.x = px[j];
                target_point.y = py[j];
                
                float dist = getDistance(now_point.x,now_point.y,target_point.x,target_point.y);
                if(dist > R) continue;

                target_point.D = now_point.D / 2;
                q.push(target_point);
                visited[j] = 1;
            }
            
            q.pop();
        }
        ans_D += maxD;
        
        // cout << "maxD: " << maxD << endl << endl;
    }
    printf("%f",ans_D);
}


