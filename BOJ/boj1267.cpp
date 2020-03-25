#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    /*
    M 30초 10원
    Y 60초 15원
    120 
    M -> 40
    Y -> 45
    */
    int time;
    int Ycost = 0, Mcost = 0;
    for(int i = 0; i < N; i++) {
        cin >> time;
        Ycost += (time / 30 + 1) * 10;
        Mcost += (time / 60 + 1) * 15;
    }
    
    if(Ycost > Mcost) {
        cout << "M ";
    } else if(Ycost < Mcost) {
        cout << "Y ";
    } else if(Ycost == Mcost) {
        cout << "Y M ";
    }
    cout << min(Ycost, Mcost);
    
    return 0;
}