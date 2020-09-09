/**
 * 문자열 2개가 다음과 같이 주어질때,
 * s1=string, s2=ingstr
 * 두 문자의 회전 여부를 확인하라.
 * //==접근 방법==//
 * s1 혹은 s2 문자열을 한번 더 이어붙이고
 * 다른 문자열이 이어붙인 문자열에 포함하는지 확인한다.
 * s3 = s1+s1 = stringstring
 * s3.isSubstring(s2);
 */
#include <bits/stdc++.h>
using namespace std;
bool isSubstring(string s1, string s2) {
    return s1.find(s2) < s2.length() ? true : false;
}
bool isRotate(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    return isSubstring(s1+s1,s2);
}
void solve() {
    string s1 = "string";
    string s2 = "ingstr";
    cout << isRotate(s1,s2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}