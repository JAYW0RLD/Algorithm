#include <iostream>
#include <vector>
using namespace std;
int N;
int max_time;

string my_type[51];
char my_input_type[51];
int my_input_undo[51];
int my_time[51];

vector<char> v;

int dfs(int order){
    if(order == N) return max_time;
    
    int undo_timeline = dfs(order+1);
    if(undo_timeline <= my_time[order]){
        return undo_timeline; //언도 당함
    }

    if(my_type[order] == "type"){
        v.push_back(my_input_type[order]);
        return max_time;
    }
    if(my_type[order] == "undo"){
        return my_time[order] - my_input_undo[order];
    }

    return max_time;
}

int main() {
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> my_type[i];
        if(my_type[i] == "type"){
            cin >> my_input_type[i] >> my_time[i];
        }
        else{
            cin >> my_input_undo[i] >> my_time[i];
        }
    }
    max_time = my_time[N-1]+1;

    dfs(0);
    
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i];
    }
    
    return 0;
}