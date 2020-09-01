/** 2636 치즈
 * bfs
 * 치즈 겉면만 녹여야 하는게 핵심
 * 가장자리에 치즈가 없는 것을 이용해서
 * (0,0)부터 bfs 하면서 치즈면 0으로 바꾸면 된다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int n,m;
int board[101][101];
int visit[101][101];
queue<pi> q;

void pM() {
	cout << "=========\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}		
		cout << "\n";
	}
}
void bfs(int x, int y) {
	q.push({x,y});
	visit[x][y] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(visit[nx][ny]) continue;
			if(board[nx][ny] == 1) {//치즈면 녹는다.
				board[nx][ny] = 0;
				visit[nx][ny] = 1;
			}
			else if(board[nx][ny] == 0) {//치즈가 아니면 큐에 넣는다.
				visit[nx][ny] = 1;
				q.push({nx,ny});
			}
			
		}
	}
}

void solve() {
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}		
	}

	//search
	int preCnt = 0, hour = 0;
	while (1) {
		//calc
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(board[i][j] == 1) {
					cnt++;
				}
			}
		}
		if(cnt == 0) break;
		preCnt = cnt;
		memset(visit,0,sizeof(visit));
		//melt down
		bfs(0,0);	
		// pM();
		hour++;
	}
	
	//완전히 다 없어지는 시간, 없어지기 전 치즈 개수
	cout << hour << "\n" << preCnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	solve();
    return 0;
}