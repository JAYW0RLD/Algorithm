#include <iostream>
#include <string>
using namespace std;
/*
A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0*/
int main(){
    string n;
    cin >> n;

    if(n == "A+") cout << "4.3";
    if(n == "A0") cout << "4.0";
    if(n == "A-") cout << "3.7";
    
    if(n == "B+") cout << "3.3";
    if(n == "B0") cout << "3.0";
    if(n == "B-") cout << "2.7";

    if(n == "C+") cout << "2.3";
    if(n == "C0") cout << "2.0";
    if(n == "C-") cout << "1.7";

    if(n == "D+") cout << "1.3";
    if(n == "D0") cout << "1.0";
    if(n == "D-") cout << "0.7";
    if(n == "F") cout << "0.0";
}