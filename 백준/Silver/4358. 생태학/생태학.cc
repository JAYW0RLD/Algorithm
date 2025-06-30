#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;


map<string, int> tree;

int main(){
    float total = 0;
    while(1){
        string name;
        getline(cin, name);
        if(name.empty() == true)
            break;
        tree[name] += 1;
        total += 1;
    }
    for(auto it=tree.begin();it != tree.end();it++){
        cout << fixed;
        cout << setprecision(4);
        
        cout << it->first << " ";
        cout << it->second/total * 100 << endl;
    }
}