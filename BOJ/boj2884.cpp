// 2884 알람시계 
#include <iostream>
using namespace std;
int main(void){
	int h,m;
	cin >> h >> m;
	if( m - 45 < 0 ){
		h--;
		if(h < 0){
			h = 23;
		}
		m = 60 - 45 + m;
	} else if( m - 45 >= 0 ){
		m = m - 45;
	}
	cout << h << ' ' << m;
	return 0;
}
