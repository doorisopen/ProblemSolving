/* 
 * 1924 2007년
 */
#include <bits/stdc++.h>
using namespace std;

int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string dayOfWeek[8] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int m, d; 
void solution() {
	cin >> m >> d;
	int calc = 0;
	for (int i = 1; i < m; i++) {
		calc += day[i];
	}
	calc += d;
	cout << dayOfWeek[calc%7];
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}