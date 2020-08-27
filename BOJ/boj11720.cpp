/** 11720 숫자의 합
 * 문자열 처리
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        sum += c - '0';
    }
    cout << sum;
    return 0;
}