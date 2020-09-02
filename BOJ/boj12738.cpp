/** 12738 가장 긴 증가하는 부분 수열 3
 *  dp(n^2) -> 이분탐색 (nlongn)
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;

ll n,ans;
vector<ll> v;
void solve() {
    cin >> n;
    v.push_back(-INF);
    ll num;
    for (ll i = 0; i < n; i++) {
        cin >> num;
        if(v.back() < num) {
            v.push_back(num);
            ans++;
        } else {
            *lower_bound(v.begin(),v.end(),num) = num;
        }
    }
    cout << ans++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}