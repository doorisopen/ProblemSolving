/* 
 * 2번 - 인내의 도미노 장인 호석
 */
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};//E W S N
int dy[4] = {1,-1,0,0};//E W S N
int board[101][101];
int check[101][101];
int n, m, r, x, y;
char d;
int answer = 0;

void p() {
	cout << "=========\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << check[i][j] << " ";
		}		
		cout << "\n";
	}
}
int solution() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}		
	}
	for (int i = 0; i < r; i++) {
		int dir = -1;
		cin >> x >> y >> d;
		if(d == 'E') {
			dir = 0;
		} else if(d == 'W') {
			dir = 1;
		} else if(d == 'S') {
			dir = 2;
		} else if(d == 'N') {
			dir = 3;
		}
		if(check[x][y] == 0) {
			int val = board[x][y]-1;
			check[x][y] = 1;
			answer++;
			while(val != 0) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				val--;
				if(nx<=0||nx>n||ny<=0||ny>m) break;
				if(check[nx][ny] == 0 && val < board[nx][ny]-1) {
					val = board[nx][ny]-1;
				}
				if(check[nx][ny] == 0) {
					answer++;
				}
				check[nx][ny] = 1;
				x = nx, y = ny; 
			}
		}
		cin >> x >> y;
		if(check[x][y]) {
			check[x][y] = 0;
		}
		// p();
	}
	cout << answer << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(check[i][j] == 0) {
				cout << "S ";
			} else {
				cout << "F ";
			}
		}		
		cout << "\n";
	}
    return 0;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution();
	return 0;
}