#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char board[6][6];
bool visit[6][6];//visit: 25->7개 선택, visit_check: 인접한지 확인
int maketeam = 0;

void printMap() {
    cout << "===========\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isConnected() {
    int r,c,team=0,teams=0;
    //x,y check
    queue<pi> q;
    bool visit_check[6][6] = {false};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(visit[i][j]) {
                r=i, c=j;                
                break;
            }
        }
    }
    q.push({r,c});
    visit_check[r][c] = true;
    //neighbor bfs
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 5 || ny >= 5 || nx < 0 || ny < 0) continue;
            if(visit_check[nx][ny] || !visit[nx][ny]) continue;
            visit_check[nx][ny] = true;
            q.push({nx,ny});
        }
    }

    //team check
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(visit_check[i][j]) {
                if(board[i][j] == 'S'){
                    teams++;
                }
                team++;
            }
        }
    }
    
    if(team == 7 && teams >= 4) {
        return true;
    } else {
        return false;
    }
}
void solve(int depth, int idx) {
    if(depth == 7&&isConnected()) {
        maketeam++;
        return;
    }
    for (int i = idx+1; i < 25; i++) {
        int x = i/5, y = i%5;
        visit[x][y] = true;
        solve(depth+1,i);
        visit[x][y] = false;
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    
    //search
    solve(0,-1);
    cout << maketeam;
    return 0;
}
/*
YYYYY
SYSYS
YYYYY
YSYYS
YYYYY
2

SSSSS
SSSSS
SSSSS
SSSSS
SSSSS
3546 != 4152

YYYYY
YYYYY
YYYYY
YYYYY
YYYYY
0
*/