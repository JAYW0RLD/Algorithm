#include <stdio.h>

int arr[100][100] = {0,};
int visited[100][100] = {0,};
int Y,X;
int map_x[] = {1,-1, 0, 0,  1,-1, 1, -1};
int map_y[] = {0, 0, 1, -1 ,1,-1,-1, 1};

int ans = 0;

// 탑인가?
int dfs(int y, int x){
    int istop = 1;
    if(visited[y][x] == 0)
        visited[y][x] = 1;
    else
        return -1;

    for(int i=0;i<8;i++){
        int sy = y + map_y[i];
        int sx = x + map_x[i];

        if(0 <= sx && sx < X && 0 <= sy && sy < Y){
            if(arr[sy][sx] > arr[y][x]){
                istop = 0;
            }
            if(arr[sy][sx] == arr[y][x]){
                int ret = dfs(sy, sx);
                if(ret == 0)
                    istop = 0;
            }
        }
    }

    if(istop == 1)
        return 1;
    else
        return 0;
}

int main(){
    scanf("%d %d",&Y ,&X);
    for(int i=0;i<Y;i++){
        for(int t=0;t<X;t++){
            scanf("%d",&arr[i][t]);
        }
    }

    for(int i=0;i<Y;i++){
        for(int t=0;t<X;t++){
            if(visited[i][t] == 0){
                int ret = dfs(i, t);
                ans += ret==1 ? 1 : 0;
                // if(ret==1) printf("top is %d %d\n",i,t);
            }

            // for(int y=0;y<Y;y++){
            //     for(int x=0;x<X;x++){
            //         printf("%d ",visited[y][x]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    }

    printf("%d", ans);
    // scanf("%d",&ans);

    return 0;
}