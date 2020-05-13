#include <bits/stdc++.h>
using namespace std;
#define ll long long

int r, c;
char board[1004][1004];
int fireVisit[1004][1004];
int jihunVisit[1004][1004];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, int> > fire;
queue<pair<int, int> > jihun;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            fireVisit[i][j] = -1;
            jihunVisit[i][j] = -1;
            if(board[i][j] == 'F') {
                fire.push({i,j});
                fireVisit[i][j] = 0;
            }
            if(board[i][j] == 'J') {
                jihun.push({i,j});
                jihunVisit[i][j] = 0;
            }
        }
    }
    
    
    while (!fire.empty()) {
        auto cur = fire.front(); fire.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(fireVisit[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fireVisit[nx][ny] = fireVisit[cur.first][cur.second] + 1;
            fire.push({nx, ny});
        }
    }

    while (!jihun.empty()) {
        auto cur = jihun.front(); jihun.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            //탈출성공
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << jihunVisit[cur.first][cur.second] + 1;
                return 0;
            }
            if(jihunVisit[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(fireVisit[nx][ny] != -1 && fireVisit[nx][ny] <= jihunVisit[cur.first][cur.second] + 1) continue;
            jihunVisit[nx][ny] = jihunVisit[cur.first][cur.second] + 1;
            jihun.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}