/*
 * 17144 미세먼지 안녕! 
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int rd[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int board[51][51];
vector<pi> machine;
vector<pi> dust;
int r,c,t;
void p() {
    cout << "---------\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
void spread() {
    int check[51][51] = {0};
    //dust init
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            check[i][j] = board[i][j];
        }
    }
    //spread
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(board[i][j]) {
                vector<pi> spreadP;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];   
                    int ny = j + dy[dir];
                    if(nx >= r || ny >= c || nx < 0 || ny < 0) continue;
                    if(board[nx][ny] == -1) continue;
                    spreadP.push_back({nx,ny});
                }
                int spreadDust = board[i][j]/5;
                for (int k = 0; k < spreadP.size(); k++) {
                    int x = spreadP[k].first;
                    int y = spreadP[k].second;
                    check[x][y] += spreadDust;
                }
                check[i][j] -= (spreadDust*spreadP.size());                
            }
        }
    }
    //copy
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] = check[i][j];
        }
    }
}
void cleaning() {
    //반시계
    int rx = machine[0].first;
    int ry = machine[0].second;
    int rcx = rx, rcy = ry;//시작점
    for (int dir = 0; dir < 4; dir++) {
        while (1) {
            int nx = rcx + rd[dir][0];
            int ny = rcy + rd[dir][1];
            if(nx < 0 || nx > rx || ny >= c) break;
            if(nx == rx && ny == ry) break;
            if(board[rcx][rcy] == -1) {
                board[nx][ny] = 0;
            } else {
                board[rcx][rcy] = board[nx][ny];
                board[nx][ny] = 0;
            }            
            rcx = nx, rcy = ny;
        }
    }
    
    //시계
    int x = machine[1].first;
    int y = machine[1].second;
    int cx = x, cy = y;
    for (int dir = 0; dir < 4; dir++) {
        while (1) {
            int nx,ny;
            if(dir%2 == 0) {
                nx = cx - rd[dir][0];
                ny = cy - rd[dir][1];
            } else {
                nx = cx + rd[dir][0];
                ny = cy + rd[dir][1];
            }
            if(nx >= r || nx < x || ny >= c) break;
            if(nx == x && ny == y) break;
            if(board[cx][cy] == -1) {
                board[nx][ny] = 0;
            } else {
                board[cx][cy] = board[nx][ny];
                board[nx][ny] = 0;
            }            
            cx = nx, cy = ny;
        }
    }
}
void solve() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if(board[i][j] == -1) {
                machine.push_back({i,j});
            }
        }        
    }
    sort(machine.begin(), machine.end());//0 top 1 bottom
    while(t--) {
        spread();
        cleaning();
    }
    
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(board[i][j] > 0) {
                res += board[i][j];
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}