/* 
 * 10430 나머지
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	//input
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a+b)%c << "\n";
	cout << ((a%c)+(b%c))%c << "\n";
	cout << (a*b)%c << "\n";
	cout << ((a%c)*(b%c))%c << "\n";
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}