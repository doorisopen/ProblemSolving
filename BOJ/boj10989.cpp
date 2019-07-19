// 수 정렬하기 3
// Counting Sort
 
#include <stdio.h>

int count[10001];
int n, max=1;

int main(void){
	int tmp;
	scanf("%d", &n);
	

	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		if(max <= tmp){
			max = tmp;
		}
		count[tmp]++;
	}
	
	for(int i = 0; i <= max; i++){
		while(count[i] != 0){
			printf("%d\n", i);
			count[i]--;
		}
	}
	return 0;
} 
