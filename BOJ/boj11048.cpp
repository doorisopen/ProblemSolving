/** 11048 이동하기
 *  dp
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1001][1001];
int dp[1001][1001];

void moveToNM(int x, int y) {
    dp[x][y] = board[x][y];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]+board[i][j+1]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+board[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+board[i+1][j+1]);
        }
    }
}

void solve() {
    //input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    //search
    moveToNM(1,1);
    //result
    cout << dp[n][m];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}