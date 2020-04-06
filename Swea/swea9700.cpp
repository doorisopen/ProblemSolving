#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    double p, q, s1 = 0, s2 = 0;
    for(int i = 1; i <= t; i++) {
        cin >> p >> q;
        s1 = (1-p) * q;
        s2 = p * (1-q) * q;
        s1 < s2 ? cout << "#" << i << " YES\n" : cout << "#" << i << " NO\n"; 
    }
    return 0;
}