/* 
 * 1546 평균
 */
#include <bits/stdc++.h>
using namespace std;

void solution() {
	//input
	int n, num, sum = 0, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		mx = max(mx, num);
		sum += num;
	}
	cout << round((double)sum/mx*100/n*100)/100.0;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}