/* 
 * 2960 에라토스테네스의 체
 */
#include <bits/stdc++.h>
using namespace std;
int prime[1001];
int n, k, cnt = 0;
void sieve() {

	for (int i = 2; i <= n; i++) {
		if(prime[i] > 0) continue;
		for (int j = i; j <= n; j+=i) {
			if(prime[j] > 0) continue;
			prime[j] = j;
			cnt++;
			if(cnt == k) {
				cout << j << "\n";
				return;
			}
		}		
	}
}
void solution() {
	cin >> n >> k;
	sieve();
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}