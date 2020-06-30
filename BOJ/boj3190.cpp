// BOJ 3190 뱀
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,char> pi;

int board[101][101];
int visit[101][101];
int n, k, moveCnt, cnt = 0;
int cx = 0, cy = 1;
queue<pi> q;
queue<pi> snack;

void printMap() {
    cout << "===================\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
}

void changeDir(char d) {
    if(cx == 1) {
        if(d == 'D') {
            cx = 0;
            cy -= 1;
        } else {
            cx = 0;
            cy += 1;
        }
        return;
    }
    if(cx == -1) {
        if(d == 'D') {
            cx = 0;
            cy += 1;
        } else {
            cx = 0;
            cy -= 1;
        }
        return;
    }
    if(cy == 1) {
        if(d == 'D') {
            cx += 1;
            cy = 0;
        } else {
            cx -= 1;
            cy = 0;
        }
        return;
    }
    if(cy == -1) {
        if(d == 'D') {
            cx -= 1;
            cy = 0;
        } else {
            cx += 1;
            cy = 0;   
        }
        return;
    }
}

void game(int x, int y) {
    snack.push({x,y});
    while(1) {
        auto cur = q.front(); q.pop();
        
        while(1) {
            //시간초 동일할때
            if(cnt == cur.first) {
                //방향 전환
                changeDir(cur.second);
                break;
            }
            int nx = x + cx;
            int ny = y + cy;
            if(nx > n || ny > n || nx < 1 || ny < 1) {
                return;
            }
            if(visit[nx][ny] == 1) {
                return;
            }
            if(board[nx][ny] != 2) {
                visit[snack.front().first][snack.front().second] = 0;
                snack.pop();
            } else {
                board[nx][ny] = 0;
            }
            visit[nx][ny] = 1;
            snack.push({nx,ny});
            x = nx; y = ny;
            cnt++;
            // printMap();
        }   
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 2;
    }
    cin >> moveCnt;
    for (int i = 0; i < moveCnt; i++) {        
        int sec;
        char d;
        cin >> sec >> d;
        q.push({sec, d});
    }
       
    game(1,1);
    cout << cnt+1;
    
    return 0;
}