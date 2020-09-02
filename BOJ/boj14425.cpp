/** 14425 문자열 집합
 * 문자열
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<string> s;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, cnt = 0;
    string str;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if(s.find(str)!=s.end()) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
