#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 0x7f7f7f7f;
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int kx[8]= {-1,-2,-2,-1,1,2,2,1};
int ky[8]= {-2,-1,1,2,2,1,-1,-2};

int k, w, h;
int board[205][205];
int visit[205][205][31];
queue<tuple<int, int, int> > q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> k;
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> board[i][j];    
        }
    }
    
    // visit init
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int c = 0; c <= k; c++) {
                visit[i][j][c] = -1;
            }
        }
    }
    q.push({1,1,0});
    visit[1][1][0] = 0;
    
    //search
    while (!q.empty()) {
        int x, y, z;
        tie(x,y,z) = q.front(); 
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || ny < 1 || nx > h || ny > w) continue;
            if(board[nx][ny] != 0 || visit[nx][ny][z] != -1) continue;
            visit[nx][ny][z] = visit[x][y][z] + 1;
            q.push({nx, ny, z});
        }
        //k번만큼 이동 횟수를 못채웠으면
        if(z != k) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + kx[dir];
                int ny = y + ky[dir];
                if(nx < 1 || ny < 1 || nx > h || ny > w) continue;
                if(board[nx][ny] != 0 || visit[nx][ny][z+1] != -1) continue;
                visit[nx][ny][z+1] = visit[x][y][z] + 1;
                q.push({nx, ny, z+1});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        if(visit[h][w][i] == -1) continue;
        ans = min(ans, visit[h][w][i]);
    }
    if(ans == INF) ans = -1;
    cout << ans;

    // cout << "\n";
    // for (int c = 0; c <= k; c++)
    // {
    //     for (int i = 1; i <= h; i++)
    //     {
    //         for (int j = 1; j <= w; j++)
    //         {
    //             cout << visit[i][j][c] << " ";
    //         }        
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    
    return 0;
}