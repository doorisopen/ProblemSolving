/* 
 * 15688 수 정렬하기 5
 */
#include <bits/stdc++.h>
using namespace std;

int arr[2000001];
void solution() {
    int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr[n+1000000]++;
	}
	for (int i = 0; i < 2000001; i++) {
		int cnt = arr[i];
		while (cnt--) {
			cout << i-1000000 << "\n";
		}
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}