// 2577 - 숫자의 개수 
#include <stdio.h>

int main(void) {
	int a,b,c,mul=0;
	long long int tmp = 1;
	int num[10]={0};
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	mul = (a * b * c);

	for(int i = mul; i > 0; i /= 10){
		++num[i % 10];
	}
	
	for(int i = 0; i < 10; i++){
		printf("%d\n",num[i]);
	}
	
	return 0;
}
