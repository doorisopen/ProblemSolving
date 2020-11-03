/* 
 * 2168 타일 위의 대각선
 */
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}
void solution() {
	int x, y;
	cin >> x >> y;
	if(x < y) {
		x^=y^=x^=y;
	}
	cout << gcd(x,y) << "\n";
	cout << x+y-gcd(x,y) << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}