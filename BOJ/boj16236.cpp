/** BOJ 16236 아기 상어
 * https://www.acmicpc.net/problem/16236
 * 설명
    1. 아기 상어 시작 위치 저장
    2. 시작 위치에서 먹을 수 있는 물고기 탐색
    3. 큐 우선순위는 
        3-1. 가장 가까운 물고기 : visit[][]
        3-2. 3-1을 만족하는 물고기가 많으면 가장 위쪽에 있는 물고기 : x
        3-3. 3-2을 만족하는 물고기가 많으면 가장 왼쪽에 있는 물고기 : y
    4. 큐에서 하나 빼서 물고기 먹는다.
        4-1. 이때 최단 경로를 절대값(abs) 빼기로 구하면 안된다. 이유는 중간에
        자기보다 큰 물고기가 있으면 돌아서 가기때문에 절대값 빼기로 최단 경로가
        나오지 않을 수 도 있기 때문이다.
    5. 물고기를 아기상어의 무게만큼 먹으면 아기상어 무게 +1
    6. 아기 상어의 위치가 변경되면 큐와 visit을 초기화 한고 변경된 위치에서 물고기 재탐색
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int n, fish = 0, eat = 0, sec = 0;
int sx, sy, status = 2;
int board[21][21];
int visit[21][21];
int path[21][21];
queue<pi> q;
priority_queue<pair<int, pair<pi, pi> > > pq;// {-visit[][],{{-x,-y},{x,y}}}

void p2() {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << path[i][j] << " ";
        }
        cout << "  ";
        for (int j = 0; j < n; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "  ";
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }

        cout << "\n";
    }

}

void findFish() {
    for (int i = 0; i < n; i++) {
        fill(visit[i], visit[i]+n, 0);
    }
    q.push({sx,sy});
    visit[sx][sy] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        if(board[x][y] != 9 && board[x][y] != 0 && board[x][y] < status) {
            pq.push({-visit[x][y],{{-x,-y},{x,y}}});
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= n || ny >= n || nx < 0 || ny < 0 || visit[nx][ny]) continue;
            if(board[nx][ny] > status) continue;
            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                sx = i, sy = j;
            }
            if(board[i][j] != 9 && board[i][j] != 0) fish++;
        }        
    }
    
    int no = 1;
    while (fish != 0) {
        //먹을수 있는 물고기 위치 탐색
        findFish();
        
        //먹을수 있는 물고기가 없으면 종료
        if(pq.empty()) {
            break;
        } else {
            //물고기 먹방
            auto cur = pq.top(); pq.pop();
            int x = cur.second.second.first;
            int y = cur.second.second.second;
            sec += -cur.first - 1;
            // sec += (abs(sx-x)+abs(sy-y)); (틀림) 

            board[sx][sy] = 0;
            board[x][y] = 9;
            path[x][y] = no++;            
            fish--;
            eat++;
            sx = x, sy = y;
            //아기상어 무게만큼 먹으면 +1
            if(status == eat) {
                status++;
                eat = 0;
            }
            //초기화
            if(!pq.empty()) {
                while (!pq.empty()) {
                    pq.pop();
                }
            }
        }
        //print
        // p2();
    }
    
    cout << sec;
    return 0;
}
/*

4
4 3 1 1
0 0 0 0
0 0 9 0
1 2 3 4

6
0 0 0 0 0 0 
1 0 0 0 1 0
0 0 0 0 0 0
0 0 9 0 6 1
0 0 0 0 0 0
1 0 0 0 0 0

*/