// boj 1094 ¸·´ë±â
#include <iostream>

using namespace std;

int main(void) {
	
	int x, cnt = 0;
	cin >> x;
	
	while(x!=0) {
		if(x % 2 == 1) cnt++;
		x /= 2;	
	}
	cout << cnt;
	return 0;
} 
