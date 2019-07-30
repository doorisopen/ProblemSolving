// 2562 - �ִ밪 
#include <stdio.h>

int main(void){
	int num, cnt = 0, max = -1;
	
	for(int i = 1; i <= 9; i++){
		scanf("%d",&num);
		if(max < num){
			max = num;
			cnt = i;
		}
	}
	printf("%d\n%d",max ,cnt);
	
	return 0;
}
