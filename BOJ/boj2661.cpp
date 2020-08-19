/** 2661 좋은수열
 */
#include <bits/stdc++.h>
using namespace std;

int n;
bool isOut = false;
vector<int> seq;
void solve(int d) {
    if(isOut) return;
    //bad pattern check
    string str = "";
    for (int i = 0; i < seq.size(); i++) {
        str += to_string(seq[i]);
    }
    
    int wCnt = 2;
    while (d - wCnt*2 >= 0) {
        int p1 = d - wCnt*2;
        int p2 = d - wCnt;
        bool isBad = true;
        //str=1212 -> p1: [0]:1 == p2: [2]:1
        while (p2 < d) {
            if(str[p1] != str[p2]) {
                isBad = false;
            }
            p1++; p2++;
        }
        if(isBad) return;
        wCnt++;
    }
    //result
    if(d == n) {
        string str = "";
        for (int i = 0; i < seq.size(); i++) {
            str += to_string(seq[i]);
        }
        cout << str << "\n";
        isOut = true;
        return;
    }
    //search
    for (int i : {1,2,3}) {
        if(seq.size() > 0 && i == seq.back()) continue;
        seq.push_back(i);
        solve(d+1);
        seq.pop_back();
    }
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    if(n==1){
        cout << "1";
        return 0;
    }
    solve(0);
    return 0;
}