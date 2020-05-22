#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int board[301][301];
int visit[301][301];
int iceVisit[301][301];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
queue<pair<int, int> > q;
queue<pair<int, int> > iceQ;

//빙산녹이는 BFS
void bfs() {
    int aroundIce = 0;
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visit[nx][ny] == 0 && board[nx][ny] == 0) {
            aroundIce++;
        }
    }
    if(board[x][y] - aroundIce < 0) {
        board[x][y] = 0;
    } else {
        board[x][y] -= aroundIce;
    }
}

//빙산갯수를 확인하는 BFS
void iceCheckBFS(int cnt) {
    while (!iceQ.empty()) {
        int x = iceQ.front().first;
        int y = iceQ.front().second;
        iceQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0) continue;
            if(iceVisit[nx][ny] > 0) continue;

            iceVisit[nx][ny] = cnt;
            iceQ.push({nx, ny});
        }
    }
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    

    int year = 1, ice = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(visit[i][j] == 0 && board[i][j] > 0) {
                    visit[i][j] = 1;
                    q.push({i,j});
                    bfs();
                }
            }
        }
        // cout << "===========\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        //빙산 개수 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(iceVisit[i][j] == 0 && board[i][j] > 0) {
                    ice++;
                    iceVisit[i][j] = ice;
                    iceQ.push({i,j});
                    iceCheckBFS(ice);
                }
            }
        }
        //빙산이 없으면 종료
        if(ice == 0) {
            cout << 0;
            return 0;
        }
        //빙산이 2덩어리 이상이면 출력후 종료
        if(ice >= 2) {
            cout << year;
            return 0;
        } else {
            year++;
            ice = 0;
            memset(visit, 0, sizeof(visit));
            memset(iceVisit, 0, sizeof(iceVisit));
        }
    }
    
    return 0;
}