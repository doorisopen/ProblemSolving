/** 2294 동전2
 */
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n,k;
int dp[MAX];
int coin[10001];
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    //init
    for (int i = 0; i <= k; i++) {
        dp[i] = MAX;
    }
    dp[0] = 0;

    //calc
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if(j-coin[i] >= 0) {
                dp[j] = min(dp[j], dp[j-coin[i]]+1);
            }
        }
    }

    //result
    if(dp[k] == MAX) dp[k] = -1;
    cout << dp[k];
    return 0;
}