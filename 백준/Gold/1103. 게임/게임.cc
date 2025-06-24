#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[50][50];
int visited[50][50];
int dp[50][50];
int W,H;

int map_x[] = {1,-1,0,0};
int map_y[] = {0,0, 1,-1};

//내 위치부터 최대 깊이 반환
int dfs(int x,int y){
    if(0 > x || x >= W || 0 > y || y >= H || arr[y][x]=='H'-'0'){
        return 0;
    }

    if(visited[y][x] == 1){
        printf("-1");
        // int n;scanf("%d",&n);
        exit(0);
    }

    if(dp[y][x] != 0){
        return dp[y][x];
    }


    visited[y][x] = 1;
    for(int i=0;i<4;i++){
        int nx = map_x[i]* arr[y][x] + x;
        int ny = map_y[i]* arr[y][x] + y;

        int dp_n = dfs(nx,ny);

        if(dp[y][x] < dp_n){
            dp[y][x] = dp_n;
        }
        
    }
    
    visited[y][x] = 0;
    dp[y][x]+=1;
    return dp[y][x];
}

int main(){
    scanf("%d %d",&H ,&W);

    char line[2501];
    for(int i=0;i<H;i++){
        scanf("%s", line);

        for(int j=0;j<W;j++){
            arr[i][j] = line[j] - '0';
        }
    }

    printf("%d", dfs(0, 0));
    // int n;scanf("%d",&n);
    exit(0);
}