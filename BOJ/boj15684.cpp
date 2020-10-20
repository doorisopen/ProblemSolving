/* 
 * 15684 사다리 조작
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int board[31][11];
int n,m,h,answer = 999999;

void p() {
	cout << "===========\n";
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j];
		}		
		cout << "\n";
	}
}
bool run() {
	for (int no = 1; no <= n; no++) {
		int x = 1, y = no;
		while(x <= h) {
			if(board[x][y] == 1) y++;
			else if(board[x][y-1] == 1) y--;
			x++;
		}
		if(no != y) return false;
	}
	return true;
}
void select(int d, int idx) {
	if(d > 3) return;
	//run
	if(run()) {
		answer = min(answer, d);
		return;
	}
	for (int i = 1; i <= h; i++) {		
		for (int j = idx; j < n; j++) {
			if(board[i][j] || board[i][j-1] || board[i][j+1]) continue;
			board[i][j] = 1;
			select(d+1, j);
			board[i][j] = 0;
		}
	}
}

void solution() {
	//input
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int r,c;
		cin >> r >> c;
		board[r][c] = 1;
	}
	
	//select ladder
	select(0,1);
	
	if(answer == 999999) {
		answer = -1;
	}
	cout << answer;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}