/* 
 * 16234 인구 이동
 * 
 * 1.한 국가를 기준으로 4방향의 경계범위에 포함하는 인접국가를 bfs로 탐색 후 그룹번호 표시
 * 2.만약, 2중 루프결과 인접국가가 2개 이상이 한번이라도 없으면 루프 탈출 후 결과 출력
 * 3.그렇지 않으면, 그룹별로 표시된 연합국가 끼리 인구수 총합/국가 개수로 분배
 * 4.1번 으로
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int n,l,r;//크기,경계범위
int board[51][51];//국가
int check[51][51];//경계확인
int res;//결과
void p() {
	cout << "--------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}
}
int openCheck() {
	while(1) {
		memset(check,0,sizeof(check));
		//인구이동 가능 국가 확인
		int unionCnt = 1;//그룹 표시
		int outCheck = 0;//탈출 조건
		queue<pi> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(!check[i][j]) {
					int adjCnt = 1;
					check[i][j] = unionCnt;
					q.push({i,j});
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						int x = cur.first;
						int y = cur.second;
						for (int dir = 0; dir < 4; dir++) {
							int nx = x + dx[dir];
							int ny = y + dy[dir];
							if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							if(check[nx][ny] > 0) continue;
							int boundary = abs(board[x][y] - board[nx][ny]);
							if(l<=boundary && boundary<=r) {
								check[nx][ny] = unionCnt;
								adjCnt++;
								q.push({nx,ny});
							}
						}
					}
					if(adjCnt>1) {
						unionCnt++;
						outCheck++;
					} else {
						check[i][j] = 0;
					}
				}
			}
		}
		//탈출 조건
		if(outCheck==0) break;

		vector<pi> tmp[2500];//임시 그룹
		int mx = 0;//그룹 번호 최댓값
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(check[i][j]) {
					tmp[check[i][j]].push_back({i,j});
					mx = max(mx, check[i][j]);
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			int population = 0;
			//그룹별 인구수 계산
			for (int j = 0; j < tmp[i].size(); j++) {
				int x = tmp[i][j].first;
				int y = tmp[i][j].second;
				population += board[x][y];
			}
			int calc = population / tmp[i].size();
			//인구 분배
			for (int j = 0; j < tmp[i].size(); j++) {
				int x = tmp[i][j].first;
				int y = tmp[i][j].second;
				board[x][y] = calc;
			}
		}
		res++;
	}
	return res;
}
void solve() {
	//input
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << openCheck();
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}