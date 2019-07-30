// 11021 - A + B - 7
#include <stdio.h>

int main(void){
	int testcase;
	int a, b;
	
	scanf("%d",&testcase);
	for(int i = 1; i <= testcase; i++){
		scanf("%d %d",&a ,&b);
		printf("Case #%d: %d\n",i ,a+b);
	}
	
	return 0;
}
