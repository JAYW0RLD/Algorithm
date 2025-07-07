#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, O ,V,E;

int main() {
    string name;
    cin >> name;

    for(int i=0;i<name.size();i++){
       L = count(name.begin(), name.end(), 'L');
       O = count(name.begin(), name.end(), 'O');
       V = count(name.begin(), name.end(), 'V');
       E = count(name.begin(), name.end(), 'E');
    }
    int N;
    int ansM = -1;
    int ansI = -1;
    cin >> N;
    string teamName[51];
    for(int i=0;i<N;i++){
        cin >> teamName[i];
        int l, o,v,e;
        l = count(teamName[i].begin(), teamName[i].end(), 'L');
        o = count(teamName[i].begin(), teamName[i].end(), 'O');
        v = count(teamName[i].begin(), teamName[i].end(), 'V');
        e = count(teamName[i].begin(), teamName[i].end(), 'E');

        int total = 
        (L+l + O+o) * (L+l + V+v) * (L+l + E+e) * 
        (O+o + V+v) * (O+o + E+e)
        * (V+v + E+e) % 100;
        // cout << total << endl;

        if(ansM < total){
            ansI = i;
            ansM = total;
        }
        if(ansM == total){
            if(teamName[i] < teamName[ansI]){
                ansI = i;
                ansM = total;
            }
        }
    }

    cout << teamName[ansI];
    
    return 0;
}