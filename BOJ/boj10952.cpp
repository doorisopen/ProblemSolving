// 11021 - A + B - 5
#include <stdio.h>

int main(void){
	int a=-1, b=11;
	
	do {
		scanf("%d %d",&a ,&b);
		if( (a+b) != 0 ){
			printf("%d\n",a+b);
		}
	}
	while(a != 0 && b != 0);
		
	
	return 0;
}
