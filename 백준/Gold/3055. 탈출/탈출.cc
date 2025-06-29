#include <iostream>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
    int depth;
};

int R, C;
char map[501][501];

// 물과 고슴도치 방문 여부는 따로 관리
int water_visited[501][501];
int hedgehog_visited[501][501];

int map_x[] = {1, -1, 0, 0};
int map_y[] = {0, 0, 1, -1};

int water_x[2501];
int water_y[2501];
int water_num = 0;

int target_x, target_y;
int start_x, start_y;

void floodWater() {
    int tmp_water_num = water_num;
    for (int i = 0; i < tmp_water_num; i++) {
        int x = water_x[i];
        int y = water_y[i];

        for (int k = 0; k < 4; k++) {
            int next_x = x + map_x[k];
            int next_y = y + map_y[k];

            if (0 <= next_x && next_x < C && 0 <= next_y && next_y < R) {
                if ((map[next_y][next_x] == '.' || map[next_y][next_x] == 'S') && water_visited[next_y][next_x] == 0) {
                    water_visited[next_y][next_x] = 1;
                    map[next_y][next_x] = '*';

                    water_x[water_num] = next_x;
                    water_y[water_num] = next_y;
                    water_num++;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        char line[100];
        scanf("%s", line);
        for (int j = 0; j < C; j++) {
            map[i][j] = line[j];

            if (map[i][j] == '*') {
                water_x[water_num] = j;
                water_y[water_num] = i;
                water_visited[i][j] = 1;
                water_num++;
            }
            if (map[i][j] == 'D') {
                target_x = j;
                target_y = i;
            }
            if (map[i][j] == 'S') {
                start_x = j;
                start_y = i;
            }
        }
    }

    queue<point> Q;
    Q.push({start_x, start_y, 0});
    hedgehog_visited[start_y][start_x] = 1;

    int curr_depth = -1;

    while (!Q.empty()) {
        point now = Q.front();

        if (now.x == target_x && now.y == target_y) {
            printf("%d\n", now.depth);
            return 0;
        }

        if (curr_depth != now.depth) {
            floodWater();
        }
        curr_depth = now.depth;

        for (int i = 0; i < 4; i++) {
            int next_x = now.x + map_x[i];
            int next_y = now.y + map_y[i];

            if (0 <= next_x && next_x < C && 0 <= next_y && next_y < R) {
                if (hedgehog_visited[next_y][next_x] == 0 &&
                    (map[next_y][next_x] == '.' || map[next_y][next_x] == 'D')) {

                    hedgehog_visited[next_y][next_x] = 1;
                    Q.push({next_x, next_y, now.depth + 1});
                }
            }
        }

        Q.pop();
    }

    printf("KAKTUS\n");
    return 0;
}
