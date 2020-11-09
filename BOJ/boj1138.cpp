/* 
 * 1138 한 줄로 서기
 */
#include <bits/stdc++.h>
using namespace std;

void solution() {
	int n;
	cin >> n;

	int memory[11];
	vector<int> order;
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}
	for (int i = n; i > 0; i--) {
		order.insert(order.begin()+memory[i],i);
	}
	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}