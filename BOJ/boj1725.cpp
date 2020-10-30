/* 
 * 1725 히스토그램
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> board;
int histogram(int left, int right) {
	//기둥이 하나일떄,
	if(left == right) return board[left];
	int mid = (left+right)/2;
	int ret = max(histogram(left,mid),histogram(mid+1,right));
	int lo = mid, hi = mid+1;
	int height = min(board[lo],board[hi]);
	ret = max(ret, height*2);
	while(left < lo || hi < right) {
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
	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		board.push_back(val);
	}
	cout << histogram(0,board.size()-1);
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}