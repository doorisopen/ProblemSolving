/** 8958 OX퀴즈
 * 문자열 처리
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        string s;
        cin >> s;
        int cnt = 1;
        for (int j = 0; j < s.length(); j++) {
            if(s[j] == 'O') {
                sum += cnt++;
            } else {
                cnt = 1;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}