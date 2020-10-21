/* 
 * 10872 팩토리얼
 */
#include <bits/stdc++.h>
using namespace std;
int cache[12] = {1,1,2,6,24,120,720};
void solution() {
	//input
	int n;
	cin >> n;
	for (int i = 7; i <= 12; i++) {
		cache[i] = cache[i-1]*i;
	}
	cout << cache[n];
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}