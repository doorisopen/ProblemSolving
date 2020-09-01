/** 1520 내리막 길
 * dfs+dp
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int board[501][501];
int visit[501][501];
int n, m, cnt = 0;

void pM() {
    cout << "----------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
}
int dfs(int x, int y) {
    if(x == n-1 && y == m-1) return 1;        
    if(visit[x][y] == -1) {
        visit[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if(board[nx][ny] < board[x][y]) {
                visit[x][y] += dfs(nx,ny);
            }
        }
    }
    return visit[x][y];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            visit[i][j] = -1;
        }
    }
    cout << dfs(0,0);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}