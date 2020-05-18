#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
char board[101][101];
int visit[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfsRGB(int x, int y, int cnt) {
    queue<pair<int, int> > q;
    q.push({x, y});
    char startChar = board[x][y];

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] > 0) continue;
            if(board[nx][ny] != startChar) continue;
            visit[nx][ny] = cnt;
            q.push({nx, ny});
        }
    }
}
void bfsRG(int x, int y, int cnt) {
    queue<pair<int, int> > q;
    q.push({x, y});
    char startChar = board[x][y];

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] > 0) continue;
            if(startChar == 'R' || startChar == 'G') {
                if(board[nx][ny] == 'B') continue;
            } else {
                if(board[nx][ny] == 'R' || board[nx][ny] == 'G') {
                    continue;
                }
            }
            visit[nx][ny] = cnt;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    int rgbpeople = 0, rgpeople = 0;
    //정상인 bfs -> r, g, b 체크
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visit[i][j] == 0) {
                bfsRGB(i,j,++rgbpeople);
            }
        }
    }
    //적록색약 bfs -> rg, b 체크
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visit[i][j] == 0) {
                bfsRG(i,j,++rgpeople);
            }
        }
    }
    
    
    // cout << "=====\n";
    // for (int i = 0; i < n; i++) {   
    //     for (int j = 0; j < n; j++) {
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << rgbpeople << " " << rgpeople;
    return 0;
}