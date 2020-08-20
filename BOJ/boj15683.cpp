/** 15683 감시 
 * 시뮬레이션
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1}; // 북쪽, 동쪽, 남쪽, 서쪽 순서
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int board[10][10];
int check[10][10];
vector<pi> cctv;
int n,m,area=0;

void update(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if(x >= n || y >= m || x < 0 || y < 0 || check[x][y] == 6) return;
        if(check[x][y] != 0) continue;
        check[x][y] = 7;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                cctv.push_back({i,j});
            }
            if(board[i][j] == 0) area++;
        }
    }

    for (int step = 0; step < (1<<(2*cctv.size())); step++) {//4진법->각 자리수는 cctv 방향
        int tmp = step;
        //init
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                check[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < cctv.size(); i++) {
            int x = cctv[i].first;
            int y = cctv[i].second;
            int dir = tmp % 4;
            tmp /= 4;
            if(board[x][y] == 1) {
                update(x,y,dir);
            } 
            else if(board[x][y] == 2) {
                update(x,y,dir);
                update(x,y,dir+2);
            } 
            else if(board[x][y] == 3) {
                update(x,y,dir);
                update(x,y,dir+1);
            } 
            else if(board[x][y] == 4) {
                update(x,y,dir);
                update(x,y,dir+1);
                update(x,y,dir+2);
            } 
            else { // board[x][y] == 5
                update(x,y,dir);
                update(x,y,dir+1);
                update(x,y,dir+2);
                update(x,y,dir+3);
            }
        }
        //calc
        int calc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                calc+=(check[i][j] == 0);
            }
        }
        area = min(area,calc);
    }
    cout << area;
    return 0;
}