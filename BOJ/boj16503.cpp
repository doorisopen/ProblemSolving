/** 16503 괄호 없는 사칙연산
 */
#include <bits/stdc++.h>
using namespace std;
int calc(int n1, char c, int n2) {
    if(c == '+') return n1+n2;
    if(c == '-') return n1-n2;
    if(c == '*') return n1*n2;
    if(c == '/') return n1/n2;
}

void solve() {
    int mx,mn;
    int n1,n2,n3;
    char c1,c2;
    cin >> n1 >> c1 >> n2 >> c2 >> n3;
    mx = max(calc(calc(n1, c1, n2), c2, n3),calc(n1, c1, calc(n2, c2, n3)));
    mn = min(calc(calc(n1, c1, n2), c2, n3),calc(n1, c1, calc(n2, c2, n3)));
    cout << mn << "\n" << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}