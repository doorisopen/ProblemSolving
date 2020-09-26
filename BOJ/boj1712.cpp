/* 
 * 1712 손익분기점
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	//input
	ll a, b, c;
	cin >> a >> b >> c;
	if(b>=c) {
		cout << "-1\n";
	} else {
		ll val = a/(c-b)+1;
		cout << val;
	}
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}