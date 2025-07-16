#include <iostream>
#include <vector>
using namespace std;
vector<int> child[51];// child[parat] = {child1234}
int del_idx;

int leafCnt;
void getLeafNode(int idx){
    if(child[idx].empty() || (child[idx].size() == 1 && child[idx].back() == del_idx)){
        leafCnt += 1;
        return;
    }
    
    while(!child[idx].empty()){
        int child_idx = child[idx].back();
        child[idx].pop_back();
        if(child_idx == del_idx) continue;

        getLeafNode(child_idx);
    }
    
    return;
}

vector<int> top_nodes;

int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        if(input == -1) {
            top_nodes.push_back(i);
            continue;
        }
        child[input].push_back(i);
    }
    cin >> del_idx;

    while(!top_nodes.empty()){
        int top_node = top_nodes.back();
        if(top_node != del_idx)
            getLeafNode(top_node);
        top_nodes.pop_back();
    }

    cout << leafCnt;
    
    return 0;
}