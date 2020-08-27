/** 11721 열 개씩 끊어 출력하기
 * 문자열 처리
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i+=10) {
        cout << s.substr(i,10) << "\n";
    }
    return 0;
}