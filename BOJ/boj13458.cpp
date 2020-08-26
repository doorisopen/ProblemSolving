/** 13458 시험 감독
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[1000001];
ll b, c, cnt = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; i++) {
        a[i]-=b;
        cnt++;
        if(a[i] > 0) {
            ll tmp = a[i]/c;
            if(a[i]%c != 0) tmp++;
            cnt += tmp;
        }
    }
    cout << cnt;
    return 0;
}