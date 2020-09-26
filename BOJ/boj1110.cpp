/* 
 * 1110 더하기 사이클
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	//input
	int n;
	cin >> n;
	int tmp = n;
	int cnt = 1;
	while (1) {
		int f = tmp/10;
		int s = tmp%10;
		int nw = f+s;
		if(nw > 9) {
			nw %= 10; 
		}
		string str = to_string(s)+to_string(nw);
		if(stoi(str) == n) break;
		tmp = stoi(str);
		cnt++;
	}
	cout << cnt;
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}