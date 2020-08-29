/** 2748 피보나치 수
 * 동적 계획법
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[101];
ll dp(int x) {
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = dp(x-1) + dp(x-2);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}