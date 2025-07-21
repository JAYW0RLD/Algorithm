#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
char arr[11][5][3];
int N;

string myarr[5]={
"###...#.###.###.#.#.###.###.###.###.###",
"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
"#.#...#.###.###.###.###.###...#.###.###",
"#.#...#.#.....#...#...#.#.#...#.#.#...#",
"###...#.###.###...#.###.###...#.###.###"
};

float canbeNum(int arr_i){
    float ans = 0;
    int cnt = 0;
    for(int t=0;t<10;t++){
        int availFlag = 1;
        for(int i=0;i<5;i++){
            for(int k=4*t;k<4*t+3;k++){
                if(arr[arr_i][i][k-4*t] == '#' && myarr[i][k] == '.'){
                    //아님
                    availFlag = 0;
                    break;
                }
            }

            if(availFlag==0) break;
        }

        if(availFlag == 1){
            cnt += 1;
            ans += t;
        }
    }

    if(cnt == 0) return -1;
    
    return ans/cnt;
}

int main() {
    
    cin >> N;
    for(int i=0;i<5;i++){
        string str;
        cin >> str;
        for(int t=0;t<N;t++){
            for(int k=4*t;k<4*t+3;k++){
                arr[t][i][k-4*t] = str[k];
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int y=0;y<5;y++){
    //         for(int x=0;x<3;x++){
    //             cout << arr[i][y][x];
    //         }
    //         cout << endl;
    //     }
    // }

    // for(int t=0;t<10;t++){
    //     for(int i=0;i<5;i++){
    //         for(int k=4*t;k<4*t+3;k++){
    //             cout << myarr[i][k];
    //         }
    //         cout << endl;
    //     }
    // }

    float ans=0;
    for(int i=0;i<N;i++){
        float ret=0;
        ret = canbeNum(i);
        if(ret == -1){
            cout << "-1";
            return 0;
        }
        ans += ret * pow(10, N-(i+1));
    }
    cout << ans;
    return 0;
}


//15*9 = 150
//10 * 150