/* 
 * 16985 Maaaaaaaaaze
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int dz[6] = {-1,1,0,0,0,0};//위, 아래, 북, 동, 남, 서
int dx[6] = {0,0,-1,0,1,0};
int dy[6] = {0,0,0,1,0,-1};
vector<int> makeBoard;//조합 결과
int check[5];//조합 확인
int buffer[5][5][5];//원본
int tmpBoard[5][5][5];//임시저장소
int board[5][5][5];//맵
int visit[5][5][5];//탐색 방문 확인
int answer = 9999999;

void search() {
	queue<pair<int,pi> > q;
	memset(visit,0,sizeof(visit));
	visit[0][0][0] = 1;
	q.push({0,{0,0}});
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		int z = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		if(z == 4 && x == 4 && y == 4) {
			answer = min(answer, visit[4][4][4]);
			return;
		}
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nz >= 5 || nx >= 5 || ny >= 5 || nz < 0 || nx < 0 || ny < 0) continue;
			if(board[nz][nx][ny] == 0 || visit[nz][nx][ny]) continue;
			visit[nz][nx][ny] = visit[z][x][y] + 1;
			q.push({nz,{nx,ny}});
		}
	}
}
void rotateBoard(int floor) {
	int tmp[5][5] = {0,};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = tmpBoard[floor][i][j];
		}		
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmpBoard[floor][i][j] = tmp[5-1-j][i];
		}		
	}
}
void make(int d) {
	if(d == 5) {
		for (int i = 0; i < makeBoard.size(); i++) {
			int floor = makeBoard[i];
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					board[i][j][k] = tmpBoard[floor][j][k];
				}
			}
		}
		//search
		if(board[0][0][0] == 1 && board[4][4][4] == 1) {
			search();
		}
	}

	for (int i = 0; i < 5; i++) {
		if(!check[i]) {
			check[i] = 1;
			makeBoard.push_back(i);
			make(d+1);
			check[i] = 0;
			makeBoard.pop_back();
		}
	}
}
void solution() {
	//input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> buffer[i][j][k];
			}
		}
	}
	for (int step = 0; step < 1024; step++) {
		int brute = step;
		//copy
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					tmpBoard[i][j][k] = buffer[i][j][k];
				}
			}
		}
		//rotate
		for (int i = 0; i < 5; i++) {
			int count = brute%4;
			brute /= 4;
			while(count--) {
				rotateBoard(i);
			}
		}
		//make
		memset(check,0,sizeof(check));
		makeBoard.clear();
		make(0);
		
		
	}
	if(answer == 9999999) {
		cout << -1;
	} else {
		cout << answer-1;
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}