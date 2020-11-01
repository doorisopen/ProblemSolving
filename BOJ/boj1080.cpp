/* 
 * 1080 행렬
 */
#include <bits/stdc++.h>
using namespace std;

char a[51][51];
char b[51][51];
int n,m,answer=0;
void toggle(int x, int y) {
	for (int i = x; i < x+3; i++) {
		for (int j = y; j < y+3; j++) {
			a[i][j] == '0' ? a[i][j] = '1' : a[i][j] = '0';
		}
	}
}
void solution() {
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	//greedy
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			if(a[i][j] == b[i][j]) continue;
			answer++;
			toggle(i,j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) {
				answer = -1;
			}
		}
	}
	cout << answer << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}