// 2438 - �� ���1 
#include <stdio.h>

int main(void) {
	int s;
	scanf("%d",&s);
	for(int i = 0; i < s; i++){
		for(int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");	
	}
		
	return 0;
}
