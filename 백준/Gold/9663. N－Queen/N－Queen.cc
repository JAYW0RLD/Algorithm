#include <iostream>
using namespace std;
int N;
int col[106], diagnol_posi[106], diagnol_neg[106];

int fillBoard(int y){
    if(y == N){
        return 1;
    } 
    
    int total = 0;
    for(int x=0;x<N;x++){
        if(col[x] == 0 && diagnol_posi[y-x+N]==0 && diagnol_neg[y+x]==0){
            col[x]+=1;
            diagnol_posi[y-x+N]+=1;
            diagnol_neg[y+x]+=1;
            
            total += fillBoard(y+1);

            col[x]-=1;
            diagnol_posi[y-x+N]-=1;
            diagnol_neg[y+x]-=1;
        }
    } 

    return total;
}

int main() {
    cin >> N;

    cout << fillBoard(0);
    return 0;
}