/* 
 * 2588 곱샘
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	//input
	string n1, n2;
	cin >> n1 >> n2;
	vector<int> res;
	int val = 1, total = 0;
	for (int i = n2.length()-1; i >= 0; i--) {
		int calc = stoi(n1)*(n2[i]-'0');
		cout << calc << "\n";
		total += (calc*val);
		val *= 10;
	}
	cout << total << "\n";
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}