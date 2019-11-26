// BOJ 2875 대회or인턴 
#include <iostream>
#include <algorithm>
using namespace std;

int f,m,k;
int main(void) {
	cin >> f >> m >> k;

	while(k-- > 0) {
		if(m*2 > f) {
			m--;
		} else {
			f--;
		}	
	}
	cout << ((m * 2 > f) ? f / 2 : m) << endl;
	
	return 0;
} 
