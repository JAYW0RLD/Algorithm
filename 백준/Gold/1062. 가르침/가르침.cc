#include <iostream>
#include <vector>
using namespace std;

char checkwords[30];
bool words[51][30];
int N,M; 
int max_ans;

void teach(int M, int lastWord){
    if(M==0){
        int ans=0;

        for(int i=0;i<N;i++){
            int breakFlag=0;
            for(int t=0;t<='z'-'a';t++){
                if(words[i][t] == 1){
                    if(checkwords[t] == 1){
                        
                    }
                    else{
                        breakFlag=1;
                        break;
                    }
                }
            }
            if(breakFlag == 0){
                ans++;
            }
        }

        max_ans = max(ans, max_ans);
        return;
    }
    
    for(int i=lastWord;i<='z'-'a';i++){
        if(checkwords[i] == 0){
            checkwords[i] = 1;
            teach(M-1, i+1);
            checkwords[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        for(int t=0;t<input.size();t++){
            words[i][input[t]-'a'] = 1;
        }
    }
    checkwords['a'-'a'] = 1;
    checkwords['n'-'a'] = 1;
    checkwords['t'-'a'] = 1;
    checkwords['i'-'a'] = 1;
    checkwords['c'-'a'] = 1;
    M -= 5;

    teach(M, 'a'-'a');

    cout << max_ans;
    return 0;
}


// antic
// 1
// c
// hello
// r


// 4
// b
// x
// d
// e
// f
// g
// h
// j
// k