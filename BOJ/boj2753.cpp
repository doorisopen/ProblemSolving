// 2753 - À±³â
#include <stdio.h>

int isLeapYear(int y){
	
	if(y % 400 == 0) return 1;
	else if(y % 4 == 0 && y % 100 > 0) return 1;
	else return 0;
}

int main(void){
	int y;
	scanf("%d",&y);
	printf("%d",isLeapYear(y));	
	return 0;
}
