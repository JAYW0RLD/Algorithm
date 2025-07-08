#include <iostream>
#include <algorithm>
using namespace std;

int crain[51];
int maxIdx_crain[51];

int box[10001];
int visited[10001];

int main() {
    int N; cin >> N;
    for(int i=0;i<N;i++){
        cin >> crain[i];
    }
    sort(crain, crain+N);
    
    int M; cin >> M;    
    for(int i=0;i<M;i++){
        cin >> box[i];
    }

    sort(box, box+M);

    for(int j=0;j<N;j++){
        int start_pos = j-1>=0 ? maxIdx_crain[j-1] : 0;
        
        for(int i=start_pos;i<M;i++){ //크래인 최대 위치로 옮기기
            if(crain[j] < box[i]){
                maxIdx_crain[j] = i-1;
                break;
            }
            else if(crain[j] >= box[M-1]){
                maxIdx_crain[j] = M-1;
                break;
            }
        }
    }

    if(maxIdx_crain[N-1] != M-1){
        cout << "-1";
        return 0;
    }

    int end_cnt=0;
    int play_time=0;
    while(end_cnt < M){
        play_time+=1;
        
        for(int i=0;i<N;i++){ //모든 크래인을 사용
            int curr_pos = maxIdx_crain[i];
            if(curr_pos < 0) continue;
            
            if(visited[curr_pos] == 1){ // 방문했다면
                while(visited[curr_pos] == 1){ // 방문 안할때까지 아래로 가서
                    curr_pos -= 1;
                    if(curr_pos < 0) break;
                }
                maxIdx_crain[i] = curr_pos; // 그 위치를 크레인 위치 삼고
                if(curr_pos < 0) continue;
            }

            if(visited[curr_pos] == 0){
                visited[curr_pos] = 1; //들어잇
                
                maxIdx_crain[i] -= 1;
                end_cnt += 1;
            }
        }

        // for(int i=0;i<N;i++){
        //     cout << maxIdx_crain[i] << " ";
        // }
        //     cout << "\n";

        // for(int i=0;i<M;i++){
        //     cout << visited[i] << " ";
        // }
        //     cout << "\n";
        //     cout << "\n";


         // end_cnt += 1;
    }

    cout << play_time;
    return 0;
}


















