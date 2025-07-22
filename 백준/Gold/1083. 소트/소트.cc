#include <iostream>
#include <math.h>
using namespace std;

//최악의 경우 1000000s * 50n = 50,000,000

int main() {
    int N, S, arr[51];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    cin >> S;

    for(int start_idx=0;start_idx<N;start_idx++){
        int max_inS_idx = start_idx;
        for(int i=start_idx;i<=start_idx+S && i < N;i++){
            if(arr[i] > arr[max_inS_idx]){
                max_inS_idx = i;
            }
        }
    
        for(int i=max_inS_idx;i>start_idx;i--){
            int tmp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = tmp;
        }
    
        S -= (max_inS_idx-start_idx);
    }

    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    return 0;
}