#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<pair<int, int> > tower;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, h;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h;
        while (!tower.empty()) {
            if(tower.top().second > h) {
                cout << tower.top().first << " ";
                break;
            }
            tower.pop();
        }

        if(tower.empty()) {
            cout << "0 ";
        }
        tower.push(make_pair(i, h));
    }
    return 0;
}