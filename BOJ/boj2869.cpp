/* 
 * 2869 달팽이는 올라가고 싶다
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a,b,v;
	//input
	cin >> a >> b >> v;
	if((v-b)%(a-b)==0) {
		cout << (v-b)/(a-b);
	} else {
		cout << (v-b)/(a-b)+1;
	}
}
int main(void){
	solve();
	return 0;
}