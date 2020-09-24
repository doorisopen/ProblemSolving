/* 
 * 2234 성곽
 * 첫 bfs로 방갯수와 방최대크기를 구한다.
 * 첫 bfs를 하면서 벽의 위치를 저장한다.
 * 첫 bfs 종료후 저장된 벽위치를 하나 없앤다
 * 이후 bfs로 방의 최대 크기를 구한다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = {0,-1,0,1};//서북동남
const int dy[4] = {-1,0,1,0};//서북동남
int board[51][51];
int check[51][51];//board복사를 위한 배열
int visit[51][51];//방문처리
vector<int> wall[51][51];//벽위치
queue<pi> q;
bool breakCheck;//벽 저장 여부
int roomCnt, roomSize, maxSize;//결과
int m,n;

void p() {
	cout << "============\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j] << " ";
		}		
		cout << "\n";
	}
}
void bfs(int r, int c) {
	visit[r][c] = 1;
	q.push({r,c});
	int tmpCnt = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		int val = board[x][y];
		tmpCnt++;
		for (int dir = 0; dir < 4; dir++) {
			if(!(val & 1)) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if(!visit[nx][ny]) {
						visit[nx][ny] = visit[x][y] + 1;
						q.push({nx,ny});
					}
				}
			} else {
				if(!breakCheck) {
					wall[x][y].push_back(1<<dir);
				}
			}
			val = val >> 1;
		}
	}
	if(!breakCheck) {
		roomSize = max(roomSize, tmpCnt);
	} else {
		maxSize = max(maxSize,tmpCnt);
	}
}

void solve() {
	//input
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			check[i][j] = board[i][j];
		}		
	}
	//방 개수, 방 최대 크기 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(!visit[i][j]) {
				roomCnt++;
				bfs(i,j);
			}
		}		
	}

	//벽 하나 부셨을때 방 최대 크기
	breakCheck = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < wall[i][j].size(); k++) {
				memset(visit,0,sizeof(visit));
				board[i][j] ^= wall[i][j][k];
				if(!visit[i][j]) {
					bfs(i,j);
				}
				board[i][j] = check[i][j];
			}
		}		
	}
	cout << roomCnt << "\n" << roomSize << "\n" << maxSize;
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}