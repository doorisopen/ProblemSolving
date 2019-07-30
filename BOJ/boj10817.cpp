// 10817 - ¼¼ ¼ö
#include <stdio.h>

int main(void){
	int a,b,c,max,min,mid;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a >= b && b >= c){
		max = a;
		mid = b;
		min = c;
	}else if( a >= c && c >= b){
		max = a;
		mid = c;
		min = b;
	}
	
	if(b >= a && a >= c){
		max = b;
		mid = a;
		min = c;
	}else if( b >= c && c >= a){
		max = b;
		mid = c;
		min = a;
	}
	
	if(c >= a && a >= b){
		max = c;
		mid = a;
		min = b;
	}else if( c >= b && b >= a){
		max = c;
		mid = b;
		min = a;
	}
	
	printf("%d",mid);
	return 0;
}
