/*
 * 14719 빗물
 */
#include <iostream>
using namespace std;
int h,w,res = 0;
int board[501];
void solve() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> board[i];
	}

	for (int i = 1; i < w; i++) {
		int left = i;
		int right = i;
		int lmx=board[i], rmx=board[i];
		//왼쪽 최댓값
		while (left >= 0) {
			lmx = max(lmx,board[left--]);
		}
		//오른쪽 최댓값
		while (right < w) {
			rmx = max(rmx,board[right++]);
		}
		res += (min(lmx,rmx) - board[i]);
	}
	cout << res << "\n";
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}