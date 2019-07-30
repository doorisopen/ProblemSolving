#include <stdio.h>

int d[41];
int zerocnt = 0, onecnt = 0;

int fib(int x){
	if(x == 0) {
		zerocnt++;
		return 0;
	}
	if(x == 1){
		onecnt++;
		return 1;
	} 
	if(d[x] != 0) return d[x];
	return fib(x-1) + fib(x-2);
}
int main(void){
	int testcase, num, tmp=0;
	
	scanf("%d",&testcase);
	
	for(int i = 0; i < testcase; i++){
		scanf("%d",&num);
		if( num == 0 ) printf("1 0\n");
		else if( num == 1 ) printf("0 1\n");
		else{
			fib(num);
			printf("%d %d\n",zerocnt ,onecnt);
			zerocnt = 0;
			onecnt = 0;
		}
	}

	return 0;
}

