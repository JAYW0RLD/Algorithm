#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
//2의 n승  gaaaaacttttt
int dp[501][501]; // x ~ y 까지 가장 긴 문자
string str;

// int dna(int st, int end){
//     if(st >= end) return 0;
//     if(dp[st][end] != -1) return dp[st][end];
    
//     int ret=0;
//     int little_ret=0;
//     while(st <= end){
//         if((str[st]=='a' && str[end]=='t') || (str[st]=='g' && str[end]=='c')){
//             st++;
//             end--;
//             ret += 2;
//         }
//         else{
//             little_ret=0;
//             for(int i=st;i<end;i++){
//                 little_ret = max(little_ret, dna(st, i)+dna(i+1, end));
//             }
//             break;
//         }
//     }
//     ret += little_ret;

//     dp[st][end] = ret;
//     return dp[st][end];
// }

int dna(int st, int end){
    if(st >= end) return 0;
    if(dp[st][end] != -1) return dp[st][end];
    
    int ret=0;
    if((str[st]=='a' && str[end]=='t') || (str[st]=='g' && str[end]=='c')){
        ret = dna(st+1, end-1)+2;
    }
    
    int little_ret=0;
    for(int i=st;i<end;i++){
        little_ret = max(little_ret, dna(st, i)+dna(i+1, end));
    }
    ret = max(ret, little_ret);
    
    dp[st][end] = ret;
    return dp[st][end];
}


int main() {
    cin >> str;
    memset(dp, -1, sizeof(dp));

    for(int i=0;i<str.size()-1;i++){//250
        if((str[i]=='a' && str[i+1]=='t') || (str[i]=='g' && str[i+1]=='c')){
            dp[i][i+1] = 2;
        }
    }


    cout << dna(0, str.size()-1);
    return 0;
}

