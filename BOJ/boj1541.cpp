// 1541 ÀÒ¾î¹ö¸° °ıÈ£ 
#include <cstdio>
#define ps(num) num > 0 ? num : -num; 
int num, minus = -1, min = 0;

int main(void) {
	while (scanf("%d", &num) != EOF) {
	
		if (num < 0) minus = 1;
		// minus = 1
		if (minus > 0){
			min -= ps(num);	
		}
		else{
			min += ps(num);	
		}
	}
	printf("%d\n", min);

	return 0;
}

