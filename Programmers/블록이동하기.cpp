/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 블록 이동하기
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int rdx[4] = {-1,1,1,-1};
int rdy[4] = {1,1,-1,-1};
// 1 -1 -1 1
// 1  1 -1 -1
queue<pair<pi,pi>> q;
int visit[101][101][4];
int n;

bool isOut(int x, int y) {
  return x >= n || y >= n || x < 0 || y < 0;
}
int solution(vector<vector<int>> board) {
  n = board.size();
  q.push({{0,0},{0,0}});//{{본체 좌표}, {방향, 이동시간}}
  visit[0][0][0] = 1;

  //bfs
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    int x = cur.first.first, y = cur.first.second;
    int dir = cur.second.first, time = cur.second.second;
    //날개 좌표 x, y
    int wx = x + dx[dir];
    int wy = y + dy[dir];
    //탈출 조건
    if((x == n-1 && y == n-1) || (wx == n-1 && wy == n-1)) return time;

    //4방향 이동
    int nx, ny, nwx, nwy;
    for (int i = 0; i < 4; i++) {
      nx = x + dx[i]; 
      ny = y + dy[i];
      nwx = wx + dx[i]; 
      nwy = wy + dy[i];
      if(isOut(nx,ny) || isOut(nwx,nwy)) continue;//범위 확인
      if(board[nx][ny] || board[nwx][nwy]) continue;//벽 확인
      if(visit[nx][ny][dir]) continue;//방문 확인
      visit[nx][ny][dir] = 1;
      q.push({{nx,ny},{dir,time+1}});
    }

    //본체(오른쪽) 기준 회전
    int rxCheck, ryCheck, ndir;
    for (int i = 1; i < 4; i+=2) {
      ndir = (dir+i) % 4;
      nwx = x + dx[ndir];
      nwy = y + dy[ndir];

      if(i==1) {//시계방향
        rxCheck = x + rdx[ndir]; 
        ryCheck = y + rdy[ndir];
      } else {//반시계방향
        rxCheck = x + rdx[dir]; 
        ryCheck = y + rdy[dir];
      }
      if(isOut(rxCheck,ryCheck) || isOut(nwx,nwy)) continue;
      if(board[rxCheck][ryCheck] || board[nwx][nwy]) continue;
      if(visit[x][y][ndir]) continue;
      visit[x][y][ndir] = 1;
      q.push({{x,y},{ndir,time+1}});//좌표는 그대로, 방향만 변경한다.
    }
    
    //날개(왼쪽) 기준 회전
    dir = (dir+2) % 4;//방향 반대로
    for (int i = 1; i < 4; i+=2) {
      ndir = (dir+i) % 4;
      nx = wx + dx[ndir]; 
      ny = wy + dy[ndir];
      if(i==1) {
        rxCheck = wx + rdx[ndir]; 
        ryCheck = wy + rdy[ndir];
      } else {
        rxCheck = wx + rdx[dir]; 
        ryCheck = wy + rdy[dir];
      }
      if(isOut(nx,ny) || isOut(rxCheck,ryCheck)) continue;
      if(board[rxCheck][ryCheck] || board[nx][ny]) continue;
      ndir = (ndir+2) % 4;
      
      if(visit[nx][ny][ndir]) continue;
      visit[nx][ny][ndir] = 1;
      q.push({{nx,ny},{ndir,time+1}});//날개 기준으로 본체 위치가 변경됨.
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << solution({{0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}});
  return 0;
}