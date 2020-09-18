/*
 * 11723 집합
 */
#include <bits/stdc++.h>
using namespace std;

int n, val, num;
string command;
void solve() {
	cin >> n;
	val = 0;
	while (n--) {
		cin >> command;
		if(command == "add") {
			cin >> num;
			if((val & (1 << num)) > 0) {//있으면 무시
				continue;
			} else {//없으면 추가
				val |= (1 << num);
			}
		} else if(command == "remove") {
			cin >> num;
			if((val & (1 << num)) > 0) {//있으면 삭제
				val ^= (1 << num);
			}
		} else if(command == "check") {
			cin >> num;
			if((val & (1 << num)) > 0) {
				cout << "1\n";
			} else {
				cout << "0\n";
			}
		} else if(command == "toggle") {
			cin >> num;
			if((val & (1 << num)) > 0) {//있으면 삭제
				val ^= (1 << num);
			} else {//없으면 추가
				val |= (1 << num);
			}
		} else if(command == "all") {
			for (int i = 1; i <= 20; i++) {
				val |= (1 << i);
			}	
		} else if(command == "empty") {
			val = 0;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}