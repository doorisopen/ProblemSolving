/* 
 * 4344 평균은 넘겠지
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int c,n;
	//input
	cin >> c;
	for (int i = 0; i < c; i++) {
		scanf("%d",&n);
		int val, sum = 0;
		vector<int> board;
		for (int j = 0; j < n; j++) {
			scanf("%d",&val);
			board.push_back(val);
			sum += val;
		}
		//calc
		sort(board.begin(), board.end());
		double min = (double)sum / (double)n;
		int idx = 0;
		for (int j = 0; j < board.size(); j++, idx++) {
			if(board[j] > min) break;
		}
		double per = (double)(n-idx)/(double)n*100.0;
		printf("%.3f%%\n", ceil(per*10000) / 10000);
	}
}
int main(void){
	solve();
	return 0;
}