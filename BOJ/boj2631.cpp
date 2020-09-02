/** 2631 줄세우기
 * dp
 * solution: n - LIS
 * 1~n 까지 수가 랜덤으로 주어질때
 * 증가하는 순서의 아이들은 올바른 위치에 서있고
 * 그 사이에 나머지 아이들을 넣어주면 되기 때문에 
 * 증가하는 순서의 아이들이 최대가 되어야 그 사이에 넣는
 * 아이의 수가 최소가 된다. 
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[201];
int dp[201];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }        
    }
    int mx = *max_element(dp, dp+n);
    cout << n - mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}