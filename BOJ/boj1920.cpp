#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

set<int> s;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, num;
   
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if(s.find(num) != s.end()){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}