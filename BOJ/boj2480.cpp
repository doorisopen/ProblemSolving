#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b, c, maxcost = 0, tmp = 0;

    map<int, int> m;
    cin >> a >> b >> c;
    m[a] += 1;
    m[b] += 1;
    m[c] += 1;
    
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second == 3) {
            maxcost = 10000;
            maxcost += iter->first*1000;
        }
        else if(iter->second == 2) {
            maxcost = 1000;
            maxcost += iter->first*100;
        }
        else {
            maxcost = iter->first*100;
        }
        if(maxcost > tmp) {
            tmp = maxcost;
        } else {
            maxcost = tmp;
        }
    }
    cout << maxcost << "\n";
    return 0;
}