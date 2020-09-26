/* 
 * 2578 빙고
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

vector<pi> board[26];
int row[5] = {5,5,5,5,5};//행
int col[5] = {5,5,5,5,5};//열
int lr = 5, rl = 5;//왼오, 오왼
bool isThird = false;
int res, cnt=0;

void solve() {
	//input
	int num;
	for (int i = 0; i < 25; i++) {
		cin >> num;
		board[num].push_back({i/5,i%5});
	}
	for (int i = 1; i <= 25; i++) {
		cin >> num;
		int x = board[num][0].first;
		int y = board[num][0].second;
		row[x]--; col[y]--;
		if(x==y) lr--;
		if((x+y) == 4) rl--;
		if(lr==0) {//왼오 대각
			lr = -1;
			cnt++;
		}
		if(rl==0) {//오왼 대각
			rl = -1;
			cnt++;
		}
		if(row[x] == 0) {//x행
			row[x] = -1;
			cnt++;
		}
		if(col[y] == 0) {//y열
			col[y] = -1;
			cnt++;
		}
		if(!isThird && cnt >= 3) {
			isThird = true;
			res = i;
		}
	}
	cout << res;
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}