#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,x,y,a,b,ans;
bool visit[101][101];
bool light[101][101];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
vector<pair<int, int> > board[101][101];
queue<pair<int, int> > q;

bool isConn(pair<int, int> next) {
    for (int i = 0; i < 4; i++) {
        int nx = next.first + dx[i];
        int ny = next.second + dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if(visit[nx][ny]) return 1;
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        board[x][y].push_back({a,b});
    }

    //init
    visit[1][1] = 1;
    light[1][1] = 1;
    q.push({1,1});

    //turn on light
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (auto next : board[cur.first][cur.second]) {
            if(visit[next.first][next.second]) continue;
            if(isConn(next)) {
                visit[next.first][next.second] = 1;
                q.push({next.first, next.second});
            }
            light[next.first][next.second] = 1;
        }
        //search possible light count
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if(!light[nx][ny] || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += light[i][j];
            // cout << light[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << cnt;

    return 0;
}