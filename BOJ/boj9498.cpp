// 9498 - 시험 성적 
#include <stdio.h>

int main(void) {
	int num;
	scanf("%d",&num);
	if(num >= 90 && num < 101) {
		printf("A");
	} else if(num >= 80 && num < 101) {
		printf("B");
	} else if(num >= 70 && num < 101) {
		printf("C");
	} else if(num >= 60 && num < 101) {
		printf("D");
	} else if(num >= 0 && num < 60){
		printf("F");
	}
	
	return 0;
}
