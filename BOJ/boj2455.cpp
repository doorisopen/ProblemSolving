// boj 2455 지능형 기차

#include <iostream>

using namespace std;
int station[5];

int main(void) {
	
	int down, up, max = 0;
	cin >> down >> up;
	station[1] = up;
	max = up;
	
	for(int i = 2; i <= 4; i++) {
		cin >> down >> up;
		station[i] = (station[i-1] - down) + up;
		if(max < station[i]) {
			max = station[i];
		}
	}
	cout << max;
	return 0;
}
