#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, h;
int board[105][105][105];
int visit[105][105][105];
int dz[6] = {0,0,0,0,-1,1};
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
queue<tuple<int, int, int> > q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> m >> n >> h;
    //input
    for (int floor = 0; floor < h; floor++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[floor][i][j];
                if(board[floor][i][j] == 1) {
                    q.push(make_tuple(floor, i, j));
                }
                if(board[floor][i][j] == 0){
                    visit[floor][i][j] = -1;
                }
            }

        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nz >= h || nx >= n || ny >= m || nz < 0 || nx < 0 || ny < 0) continue;
            if(visit[nz][nx][ny] >= 0) continue;

            visit[nz][nx][ny] = visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push(make_tuple(nz, nx, ny));
        }
    }
    int ans = 0;
    for (int floor = 0; floor < h; floor++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(visit[floor][i][j] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, visit[floor][i][j]); 
            }
        }
    }
    cout << ans;
    return 0;
}