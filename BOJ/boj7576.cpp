#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int board[1004][1004];
int visit[1004][1004];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int> > q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                q.push({i, j});
            }
            if(board[i][j] == 0) {
                visit[i][j] = -1;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if(visit[nx][ny] >= 0) continue;
            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx, ny});
        }   
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, visit[i][j]);            
        }
    }
    cout << ans;
    return 0;
}