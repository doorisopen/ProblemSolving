/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 기둥과 보 설치
 */
#include <bits/stdc++.h>
using namespace std;

int N;
int board[2][1001][1001];//0 기둥, 1 보
bool buildCheck(int x, int y, int item) {
  if(item == 0) {
    //바닥, 보가 있는 경우
    return y == 1 || board[1][x-1][y] || board[1][x][y] || board[0][x][y-1];
  } 
  if(item == 1) {
    //위, 오른쪽위, 왼쪽, 오른쪽
    return board[0][x][y-1] || board[0][x+1][y-1] || (board[1][x-1][y] && board[1][x+1][y]);
  }
}
bool destoryCheck(int x, int y, int item) {
  bool result = true;
  //해당 좌표 제거
  if(item == 0) board[0][x][y] -= 1;
  else board[1][x][y] -= 1;

  //배열 전체를 탐색한다.
  for (int i = 1; i <= N+1; i++) {
    if(!result) break;
    for (int j = 1; j <= N+1; j++) {
      if(board[0][i][j] && !buildCheck(i,j,0)) {
        result = false;
        break;
      }
      if(board[1][i][j] && !buildCheck(i,j,1)) {
        result = false;
        break;
      }
    }
  }
  //복구
  if(item == 0) board[0][x][y] += 1;
  else board[1][x][y] += 1;
  return result;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for (int i = 0; i < build_frame.size(); i++) {
      int x = build_frame[i][0]+1;
      int y = build_frame[i][1]+1;
      int item = build_frame[i][2];//0:기둥, 1:보
      int isBuild = build_frame[i][3];//0:삭제, 1:설치
      if(item == 0) {
        //기둥 설치
        if(isBuild && buildCheck(x,y,item)) {
          board[0][x][y] += 1;
        }
        //기둥 삭제
        if(!isBuild && destoryCheck(x,y,item)) {
          board[0][x][y] -= 1;
        }
      } else {
        //보 설치
        if(isBuild && buildCheck(x,y,item)) {
          board[1][x][y] += 1;
        }
        //보 삭제
        if(!isBuild && destoryCheck(x,y,item)) {
          board[1][x][y] -= 1;
        }
      }
    }
    
    //결과 입력
    for (int i = 1; i <= n+1; i++) {
      for (int j = 1; j <= n+1; j++) {
        vector<int> v;
        if(board[0][i][j]) {
          v.push_back(i-1);
          v.push_back(j-1);
          v.push_back(0);
          answer.push_back(v);
        }
        v.clear();
        if(board[1][i][j]) {
          v.push_back(i-1);
          v.push_back(j-1);
          v.push_back(1);
          answer.push_back(v);
        }
      }
    }
    sort(answer.begin(), answer.end());
    return answer;
}