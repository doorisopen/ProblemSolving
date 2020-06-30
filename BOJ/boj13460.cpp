// BOJ 13460 구슬탈출2
//https://yabmoons.tistory.com/229
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
const int INF = 0x7f7f7f7f;

char map[11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; // 상, 좌, 하, 우
int n, m, rx, ry, bx, by, ans = INF;
//출력
void printMap(int dir, int ix, int iy, int jx, int jy) {
    // cout << "============\n";
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << map[i][j];
    //     }    
    //     cout << "\n";
    // }
    cout << "\n======"<< dir <<"======\n";
    cout << ix << " " << iy << "\n";
    cout << jx << " " << jy << "\n";
}
//반대 진행 방향 확인
int check(int dir) {
    if(dir == 0) return 2;
    if(dir == 1) return 3;
    if(dir == 2) return 0;
    if(dir == 3) return 1;
}
void search(int crx, int cry, int cbx, int cby, int moveCnt, int dir) {
    // printMap(dir, crx, cry, cbx, cby);

    if(moveCnt > 10 || moveCnt >= ans) return;

    int rCnt = 0, bCnt = 0;
    bool isRGoal = false, isBGoal = false;
    
    //Red 이동 
    int preRx = crx, preRy = cry;
    while (1) {
        crx += dx[dir];
        cry += dy[dir];
        rCnt++;
        if(map[crx][cry] == '#') {
            crx -= dx[dir];
            cry -= dy[dir];
            rCnt--;
            break;
        }
        if(map[crx][cry] == 'O') {
            isRGoal = true;
            break;
        }
    }
    
    //Blue 이동
    int preBx = cbx, preBy = cby;
    while (1) {
        cbx += dx[dir];
        cby += dy[dir];
        bCnt++;
        if(map[cbx][cby] == '#') {
            cbx -= dx[dir];
            cby -= dy[dir];
            bCnt--;
            break;
        }
        if(map[cbx][cby] == 'O') {
            isBGoal = true;
            break;
        }
    }

    //goal
    if(isBGoal) return;
    else {
        if(isRGoal) {
            ans = min(ans, moveCnt);
            return;
        }
    }

    //겹치는 경우
    if(crx == cbx && cry == cby) {
        if(rCnt > bCnt) {
            crx -= dx[dir];
            cry -= dy[dir];
        } else {
            cbx -= dx[dir];
            cby -= dy[dir];
        }
    }

    //재귀
    for (int i = 0; i < 4; i++) {
        if(i == dir) continue;
        if(i == check(dir)) continue;
        search(crx, cry, cbx, cby, moveCnt+1, i);
    }
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j]; 
            if(map[i][j] == 'R') {
                rx = i; ry = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B') {
                bx = i; by = j;
                map[i][j] = '.';
            }
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        search(rx, ry, bx, by, 1, dir);
    }
    if(ans > 10 || ans == INF) cout << -1;
    else {
        cout << ans;
    }

    return 0;
}