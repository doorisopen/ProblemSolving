#include <bits/stdc++.h>
using namespace std;
#define ll long long

int l, r, c;
char board[31][31][31];
int visit[31][31][31];
queue<tuple<int, int, int> > q;
int dz[6] = {-1,1,0,0,0,0};
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
int sz, sx, sy;//출발z좌표, 출발x좌표, 출발y좌표
int ez, ex, ey;//탈출z좌표, 탈출x좌표, 탈출y좌표


void bfs() {
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int z = get<0>(cur);
        int x = get<1>(cur);
        int y = get<2>(cur);
        for (int i = 0; i < 6; i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nz > l || nx > r || ny > c || nz <= 0 || nx <= 0 || ny <= 0) continue;
            if(board[nz][nx][ny] == '#') continue;
            if(visit[nz][nx][ny] > -1) continue;
            visit[nz][nx][ny] = visit[z][x][y] + 1;
            q.push(make_tuple(nz,nx,ny));
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    while (1) {
        cin >> l >> r >> c;
        if(l==0&&r==0&&c==0) return 0;
        
        //visit init
        for (int height = 1; height <= l; height++) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    visit[height][i][j] = -1;
                }
            }
        }

        //board input
        for (int height = 1; height <= l; height++) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    cin >> board[height][i][j];
                    if(board[height][i][j] == 'S') {
                        sz = height; sx = i; sy = j;
                    }
                    if(board[height][i][j] == 'E') {
                        ez = height; ex = i; ey = j;
                    }
                }
            }
        }
        q.push(make_tuple(sz,sx,sy));
        visit[sz][sx][sy] = 0;
        bfs();

        //debug
        // cout << "\n=======print=======\n";
        // for (int height = 1; height <= l; height++) {
        //     for (int i = 1; i <= r; i++) {
        //         for (int j = 1; j <= c; j++) {
        //             cout << visit[height][i][j] << " ";
        //         }
        //         cout << "\n";

        //     }
        //     cout << "\n";
        // }

        //result
        if(visit[ez][ex][ey] > -1) {
            cout << "Escaped in " << visit[ez][ex][ey] << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }

        memset(board, 0, sizeof(board));
    }
    return 0;
}