/**
 * 문자열 1개가 다음과 같이 주어질때,
 * s1 = "abcdeefg" 문자열의 중복된 문자가 있는지 확인하기
 * 단, 비트연산을 활용할 것
 * 문자열은 소문자로만 이루어져있다.
 */
#include <bits/stdc++.h>
using namespace std;

bool isUnique(string s) {
    int val = 0;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if((val & (1 << c)) > 0) {// 0001 일떄 c값만큼 왼쪽 시프트
            return false;
        }
        val |= (1 << c);// 중복값이 없으면 해당 문자의 비트 값을 더한다 (or 연산)
    }
    return true;
}
void solve() {
    string s1 = "abcdeefg";
    string s2 = "abcdefgh";
    cout << isUnique(s1) << "\n";
    cout << isUnique(s2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}