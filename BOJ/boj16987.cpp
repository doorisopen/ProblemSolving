/* 
 * 16987 계란으로 계란치기
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi> egg;
int n,s,w,mx;
void strike(int cur) {
	if(cur == n) {
		int ret = 0;
		for (int i = 0; i < egg.size(); i++) {
			if(egg[i].first <= 0) ++ret;
		}
		mx = max(mx, ret);
		return;
	}
	for (int i = 0; i < egg.size(); i++) {
		if(cur != i && egg[cur].first > 0 && egg[i].first > 0) {
			egg[i].first -= egg[cur].second;
			egg[cur].first -= egg[i].second;
			strike(cur+1);
			egg[i].first += egg[cur].second;
			egg[cur].first += egg[i].second;
		}
		if(cur != i && (egg[cur].first <= 0 || egg[i].first <= 0)) {
			strike(cur+1);
		}
	}
}
void solution() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> w;
		egg.push_back({s,w});//내구도, 무게
	}
	strike(0);
	cout << mx << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}