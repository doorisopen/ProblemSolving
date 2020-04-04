#include <bits/stdc++.h>
using namespace std;

int main(void) {
    //==solution 1==//
    int x[3], y[3];
    int a, b;

    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }
    a = (x[0] == x[1]) ? x[2] : ((x[1] == x[2]) ? x[0] : x[1]);
    b = (y[0] == y[1]) ? y[2] : ((y[1] == y[2]) ? y[0] : y[1]);

    cout << a << ' ' << b;

    //==solution 2==//
    // vector<pair<int, int> > v;
    // vector<int> ans;
    // for(int i = 0; i < 3; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     v.push_back(make_pair(x,y));
    // }

    // // 0 1 -> 2
    // if(v[0].first == v[1].first) {
    //     ans.push_back(v[2].first);
    // } // 0 2 -> 1
    // else if(v[0].first == v[2].first) {
    //     ans.push_back(v[1].first);
    // } //  -> 0
    // else {
    //     ans.push_back(v[0].first);
    // }
    
    // if(v[0].second == v[1].second) {
    //     ans.push_back(v[2].second);
    // } else if(v[0].second == v[2].second) {
    //     ans.push_back(v[1].second);
    // } else {
    //     ans.push_back(v[0].second);
    // }
    // cout << ans[0] << " " << ans[1];
}