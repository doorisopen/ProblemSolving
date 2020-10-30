/* 
 * 6549 히스토그램에서 가장 큰 직사각형
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> board;
ll histogram(ll left, ll right) {
	if(left == right) return board[left];
	ll mid = (left+right)/2;
	ll ret = max(histogram(left,mid), histogram(mid+1,right));
	ll lo = mid, hi = mid+1;
	ll height = min(board[lo],board[hi]);
	ret = max(ret, height*2);
	while (left < lo || right > hi) {
		if(hi < right && (lo == left || board[lo-1] < board[hi+1])) {
			++hi;
			height = min(height, board[hi]);
		} else {
			--lo;
			height = min(height, board[lo]);
		}
		ret = max(ret, height*(hi-lo+1));
	}
	return ret;
}
void solution() {
	int num;
	while(1) {
		cin >> num;
		if(num == 0) break;
		board.clear();
		ll hight;
		for(int i = 0; i < num; i++) {
			cin >> hight;
			board.push_back(hight);
		}
		cout << histogram(0,num-1) << "\n";
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}