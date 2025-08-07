#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
char maze[50][50];
int visited[65][50][50];
int x_map[4] = {1,-1,0,0};
int y_map[4] = {0,0,1,-1};

struct point {
    int x;
    int y;
    int equippedkey=0;
    int depth=0;
};

int main() {
    int N, M;
    cin >> N >> M;
    
    point st;
    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        for(int t=0;t<M;t++){
            maze[i][t] = input[t];
            if(maze[i][t] == '0'){
                st.x = t;
                st.y = i;
            }
        }
    }

    queue<point> q;
    q.push(st);
    while(!q.empty()){
        point now = q.front();
        q.pop();
        
        if(visited[now.equippedkey][now.y][now.x] == 1){
            continue;
        }
        // cout << "x,y " << now.x << ","<< now.y << "val " << maze[now.y][now.x] << "  depth " << now.depth << endl;

        if(maze[now.y][now.x] == '1'){
            cout << now.depth;
            return 0;
        }

        visited[now.equippedkey][now.y][now.x] = 1;

        for(int i=0;i<4;i++){
            point next;
            next.x = now.x + x_map[i];
            next.y = now.y + y_map[i];
            if(next.x < 0 || next.x >= M || next.y < 0 || next.y >= N){
                continue;
            }
            next.equippedkey = now.equippedkey;
            next.depth = now.depth+1;

            if(maze[next.y][next.x] == '#'){
                continue;
            }
            // else if(maze[next.y][next.x] == '.' || maze[next.y][next.x] == '1'){
            //     q.push(next);
            // }
            else if('a' <= maze[next.y][next.x] && maze[next.y][next.x] <= 'f'){ //알파벳
                next.equippedkey |= (1 << (maze[next.y][next.x] - 'a'));
                q.push(next);
            }
            else if('A' <= maze[next.y][next.x] &&maze[next.y][next.x] <= 'F'){ //알파벳
                if(next.equippedkey & (1 << (maze[next.y][next.x] - 'A'))){
                    q.push(next);
                }
            }
            else{
                q.push(next);
            }
        }
    }
    cout << -1;
    return 0;
}