#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int building[51];
    for(int i=0;i<N;i++){
        cin >> building[i];
    }

    int max_view_count = 0;
    for(int curr_building_idx=0;curr_building_idx<N;curr_building_idx++){
        int view_count=0;
        
        long long minTilt_building_idx = -1;
        for(int target_building_idx=curr_building_idx-1;target_building_idx>=0;target_building_idx--){
           if(minTilt_building_idx == -1){
                minTilt_building_idx = target_building_idx;
                view_count += 1;
                continue;
            }
            
            long long target_pa = (building[curr_building_idx] - building[target_building_idx]);
            long long target_ch = (curr_building_idx - target_building_idx);
            long long minTilt_pa = (building[curr_building_idx] - building[minTilt_building_idx]);
            long long minTilt_ch = (curr_building_idx - minTilt_building_idx);
            
            //curr이 위치가 더 크다-> 분자 양수
            if(target_pa*minTilt_ch >= minTilt_pa*target_ch) continue; // 접함 =조건
            else{
                // cout << target_building_idx << "target_building_idx m" << endl;
                minTilt_building_idx = target_building_idx;
                view_count += 1;
            }
        }

        long long maxTilt_building_idx= -1;
        for(int target_building_idx=curr_building_idx+1;target_building_idx<N;target_building_idx++){
            if(maxTilt_building_idx == -1){
                maxTilt_building_idx = target_building_idx;
                view_count += 1;
                continue;
            }

            long long target_pa = (building[curr_building_idx] - building[target_building_idx]);
            long long target_ch = (curr_building_idx - target_building_idx);
            long long maxTilt_pa = (building[curr_building_idx] - building[maxTilt_building_idx]);
            long long maxTilt_ch = (curr_building_idx - maxTilt_building_idx);
            
            //curr위치가 더 작다 -> 분자 음수 2번이니 노상관
            if(target_pa*maxTilt_ch <= maxTilt_pa*target_ch) continue; // 접함 조건
            else{
                // cout << target_building_idx << "target_building_idx" << endl;
                maxTilt_building_idx = target_building_idx;
                view_count += 1;
            }
        }

        // cout << view_count << "view_count\n\n"; 
        if(max_view_count < view_count)
            max_view_count = view_count;
    }

    cout << max_view_count;
    return 0;
}