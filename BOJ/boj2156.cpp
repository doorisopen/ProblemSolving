/** 2156 포도주 시식
 * 동적 계획법
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[10001];
int dp[10001];
int n;
int f() {
    for (int i = 0; i < n; i++) {
        dp[i] = max(arr[i]+dp[i-2], arr[i]+arr[i-1]+dp[i-3]);
        dp[i] = max(dp[i], dp[i-1]);
    }  
    return dp[n-1];
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << f();    
    return 0;
}
