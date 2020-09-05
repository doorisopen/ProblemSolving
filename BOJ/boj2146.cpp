/** 2146 다리만들기
 * bfs
 * 1. 섬끝을 찾아서 표시
 * 2. 섬끝에서 다른 섬으로 연결한다.
 * 3. 최단 거리 계단
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int n, ans = 9999;
int board[101][101];
int visit[101][101];
void pB() {
    cout << "-------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }        
        cout << "\n";
    }
}
void pV() {
    cout << "-------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visit[i][j] > 9) {
                cout << visit[i][j] << " ";
            } else {
                cout << visit[i][j] << "  ";
            }
        }        
        cout << "\n";
    }
}
void checkEdge(int r, int c, int edge) {
    queue<pi> q;
    visit[r][c] = 1;
    q.push({r,c});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
            if(visit[nx][ny]) continue;
            if(board[nx][ny] == 0) {
                board[x][y] = edge;
                continue;
            }
            visit[nx][ny] = 1;
            q.push({nx,ny});
        }   
    }
}
void findOtherLand(int r, int c, int edge) {
    queue<pi> q;
    visit[r][c] = 1;
    q.push({r,c});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || ny >= n || nx < 0 || ny < 0 || visit[nx][ny]) continue;
            if(board[nx][ny] == edge || board[nx][ny] == 1) continue;
            if(board[nx][ny] > 1) {
                ans = min(ans, visit[x][y]);
                continue;
            }
            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx,ny});
        }
    }
}
void init() {
    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = 0;
        }
    }
}
void solve() {
    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }        
    }
    // 외각 구하기
    int edge = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visit[i][j] && board[i][j] == 1) {
                checkEdge(i,j,edge++);
            }
        }        
    }
    // pB();
    int end = edge;    
    // 거리 구하기
    for (int no = 2; no <= end; no++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == no) {
                    init();
                    findOtherLand(i,j,no);
                }
            }        
        }
        // pV();
    }
    cout << ans-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}