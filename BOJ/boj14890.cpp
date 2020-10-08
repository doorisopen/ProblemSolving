/* 
 * 14890 경사로
 */
#include <bits/stdc++.h>
using namespace std;
int n, l;
int board[201][201];

void solve() {
	//input
	cin >> n >> l;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i+n][j] = board[j][i];
		}
	}
	int answer = 0;
	for(int i = 0; i < n*2; i++) {
		int count = 1;
		int j;
		for (j = 0; j < n-1; j++) {
			if(board[i][j] == board[i][j+1]) count++;
			else if(board[i][j]+1 == board[i][j+1] && count >= l) count = 1;
			else if(board[i][j]-1 == board[i][j+1] && count >= 0) count = -l + 1;
			else break;
		}
		if(j == n-1 && count >= 0) answer++;
	}
	cout << answer;
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}