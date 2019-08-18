// 1074 - Z  
#include <stdio.h>
#include <math.h>
using namespace std;

int N, r, c;
int cnt = 0;

void Z(int x, int y, int len) {
	
	if(x == r && y == c) {
		printf("%d", cnt);
		return ;	
	} 
	
	if(r < x + len && r >= x && c < y + len && c >= y) {
		Z(x ,y ,len/2);
		Z(x ,y + len/2 ,len/2);
		Z(x + len/2 ,y ,len/2);
		Z(x + len/2 ,y + len/2 ,len/2);
	} else {
		cnt += len * len;
	}

}
int main(void) {
	
	scanf("%d %d %d", &N, &r, &c);
	Z(0, 0, pow(2,N));
	
	return 0;
}
