/* 
 * 3052 나머지
 */
#include <bits/stdc++.h>
using namespace std;

void solution() {
	//input
	int num;
	set<int> s;
	while(!cin.eof()) {
		cin >> num;
		s.insert(num%42);
	}
	cout << s.size();
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}