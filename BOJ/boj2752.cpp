// 세수정렬
#include <stdio.h>

int array[3];

int main(void){
	int tmp, index;
	
	for(int i = 0; i < 3; i++){
		scanf("%d",&array[i]);
	}
	
	for(int i = 0; i < 3; i++){
		int a = 1000001;
		for(int j = i; j < 3; j++){
			if(a > array[j]){
				a = array[j];
				index = j;
			}
		}
		tmp = array[i];
		array[i] = array[index];
		array[index] = tmp;
	}
	
	for(int j = 0; j < 3; j++){
		printf("%d ",array[j]);
	}
	
	return 0;
}
