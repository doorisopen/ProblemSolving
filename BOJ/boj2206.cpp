#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int board[1001][1001];
int visit[1001][1001][2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs() {
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(1,1,0));
    visit[1][1][0] = 1;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);
        if(x == n && y == m) {
            return visit[x][y][z];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || visit[nx][ny][z] != 0) continue;
            if(board[nx][ny] == 0) {
                visit[nx][ny][z] = visit[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if(board[nx][ny] == 1 && z == 0) {
                visit[nx][ny][1] = visit[x][y][z] + 1;
                q.push(make_tuple(nx,ny,1));
            }
        
        }
    }
    return -1;
}

int main() {
    
    scanf("%d %d",&n ,&m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d",&board[i][j]);
        }
    }

    cout << bfs() << "\n";

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << visit[i][j][1] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}