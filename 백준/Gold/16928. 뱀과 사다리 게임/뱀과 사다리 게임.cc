#include <iostream>
#include "vector"
#include <utility>
using namespace std;

int map[101];
int ladderAndSnake[101];

void fun(int pos, int deep){
    // int emptySpace;
    // for(emptySpace = 1; emptySpace<6;emptySpace++){
    //     if(ladderAndSnake[pos + emptySpace] != 0 || pos + emptySpace == 99){
    //         emptySpace -= 1;
    //         break;
    //     }
    // }
    
    for(int i=6;i>0;i--){
        int nextPos = pos+i;
        if(nextPos > 99)
            continue;;

        if(map[nextPos] != 0 && map[nextPos] <= deep+1) 
            continue; 
        
        if(map[99] != 0 && map[99] <= deep+1)
            continue;

        if(ladderAndSnake[nextPos] == 0){
            // printf("%d에서 %d를 굴려 %d로 이동합니다.\n",pos,i,nextPos);
            map[nextPos] = deep + 1;
            fun(nextPos, deep + 1);
        }
        else{
            // printf("%d에서 %d를 굴려 - 사다리 - %d로 이동합니다. (%d + 1)\n",pos,i,ladderAndSnake[nextPos], deep);
            map[nextPos] = deep + 1;
            map[ladderAndSnake[nextPos]] = deep + 1;
            fun(ladderAndSnake[nextPos], deep + 1);
        }
    }
    return;
}

int main(){
    int a, b;
    scanf("%d %d",&a,&b);

    int q,w;
    for(int i=0;i<a;i++){
        scanf("%d %d", &q, &w);
        ladderAndSnake[q-1] = w-1;
    }

    for(int i=0;i<b;i++){
        scanf("%d %d", &q, &w);
        ladderAndSnake[q-1] = w-1;
    }

    fun(0, 0);

    // for(int x=0;x<10;x++){
    //     for(int y=0;y<10;y++){
    //         printf("%d ",map[x*10 + y]);
    //     }
    //     printf("\n"); 
    // }

    printf("%d",map[99]);
    // printf("ans %d",map[100]);
    return 0;
}