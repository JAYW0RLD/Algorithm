#include <iostream>
#include <vector>
using namespace std;

vector<int> truth_peoples;
int truth_peoples_visited[51];
vector<int> partys_peopleId[51];
vector<int> poeples_partyId[51];

// 사람 번호 - 파티 1,2,3

int main() {
    int N, M;
    cin >> N >> M;
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        truth_peoples.push_back(num);
    }

    for(int i=1;i<=M;i++){ // 파티 인덱스
        int m;
        cin >> m;
        for(int t=0;t<m;t++){
            int num; // 사람 id
            cin >> num;
            partys_peopleId[num].push_back(i);            
            poeples_partyId[i].push_back(num);            
        }
    }

//0 4
//1
//5
    //5 4 1x
        //4 4
    
    while(!truth_peoples.empty()){
        int peopleIdx = truth_peoples.back();
        truth_peoples.pop_back();

        // cout << "truth_peoples_visited " <<  peopleIdx << endl;
        truth_peoples_visited[peopleIdx] = 1;

        while(!partys_peopleId[peopleIdx].empty()){
            int partyID = partys_peopleId[peopleIdx].back();
            partys_peopleId[peopleIdx].pop_back();
        
            while(!poeples_partyId[partyID].empty()){
                int peopleID = poeples_partyId[partyID].back();
                poeples_partyId[partyID].pop_back();
                
                if(truth_peoples_visited[peopleID] == 0){
                    // cout << "partyID " << partyID << endl;
                    // cout << "peopleID " << peopleID << endl;
                    truth_peoples.push_back(peopleID);
                }
            }
        }
    }
//사람은 다 걸러짐 ㅇㅋ

    int ans = 0;
    for(int i=1;i<=M;i++){ // 파티 인덱스
        // cout << i <<  "파티인덱스\n";
        // int truthFlag = 0;

        // while(!poeples_partyId[i].empty()){
        //     int partyPeople = poeples_partyId[i].back();
        //     poeples_partyId[i].pop_back();
            
        //     cout << "partyPeople " << partyPeople << endl;
        //     cout << truth_peoples_visited[partyPeople] << endl;
            
        //     if(truth_peoples_visited[partyPeople] == 1){
        //         cout << "이 파티는 실패\n";
        //         truthFlag = 1;
        //         continue; //이 파티는 실패
        //     }
        // }
        // cout << "truthFlag " << truthFlag << endl;
        // if(truthFlag == 1)
        //     continue;

        if(!poeples_partyId[i].empty())
            ans += 1;
    }

    cout << ans;
    return 0;
}