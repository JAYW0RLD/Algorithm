#include <iostream>
#include <math.h>
using namespace std;
int mem[1000001];
int arr[1000001];

int main() {
    int N; 
    cin >> N;

    arr[1] = 1;
    int i = 1;
    while(1){
        i+=1;
        arr[i] = arr[i-1] + 4*(i-1)+1;

        int n=1;
        if(arr[i] > N) break;    
    }
    int arr_size = i-1;

    for(int i=1;i<=N;i++){
        mem[i] = 10;
    }

    for(int k=1; k<=arr_size; k++){
        mem[arr[k]] = 1;
    }

    mem[1] = 1;
    
    for(int i=1;i<=N;i++){
        for(int k=1; k<=arr_size; k++){
            if(i- arr[k] <= 0) break;
            mem[i] = min( mem[i], mem[i- arr[k]] + 1);
        }
    }

    cout << mem[N];
    return 0;
}