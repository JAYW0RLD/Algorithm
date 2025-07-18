#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    int k;
    string line_input;
    int arr[51][51];
    vector<int> zeroCnt[51];
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> line_input;
        for(int j=0;j<M;j++){
            arr[i][j] = line_input[j];
            
            if(arr[i][j] == '0'){
                zeroCnt[i].push_back(j);
            }
        }
    }
    cin >> k;
    
    int max_ans = 0;
    for(int i=0;i<N;i++){
        int ans = 0;
        //1로 만들 수 있으면
        if(zeroCnt[i].size() <= k && zeroCnt[i].size()%2 == k%2){
            //50개 행 내려가면서 111..11인 행 검출
            for(int t=0;t<N;t++){
                if(zeroCnt[i] == zeroCnt[t]){
                    ans++;
                }
            }
        }
        max_ans = max(max_ans, ans);
    }

    cout << max_ans;
    return 0;
}