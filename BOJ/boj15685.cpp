/* 
 * 15685 드레곤 커브
 * →: 0, ↑:1 , ←: 2, ↓:3
 * d=0, 
 * 0g = 0 2^0
 * 1g = 01 2^1
 * 2g = 0121 2^2
 * 3g = 01212321 2^3
 * 4g = 0121232123032321 2^4
 * 0->1
 * 1->2
 * 2->3
 * 3->0
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int board[201][201];
int pattern[4][1024] = {{0,},{1,},{2,},{3,}};
int n, x, y, d, g;

void solution() {
	//input
	cin >> n;
	for (int dir = 0; dir < 4; dir++) {
		for (int gen = 1; gen <= 10; gen++) {
			int s = (1<<(gen-1));
			int e = (1<<gen);
			for (int i = s, j = 1; i < e; i++, j+=2) {
				pattern[dir][i] = (pattern[dir][i-j]+1)%4;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {	
		cin >> x >> y >> d >> g;
		int cx = x;
		int cy = y;
		board[cy][cx] = 1;
		for (int j = 0; j < (1<<g); j++) {
			if(pattern[d][j] == 0) cx++;
			else if(pattern[d][j] == 1) cy--;
			else if(pattern[d][j] == 2) cx--;
			else if(pattern[d][j] == 3) cy++;
			board[cy][cx] = 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]) result++;
		}		
	}
	cout << result;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}