// 수 정렬하기
#include <stdio.h>
int testcase, num;
int array[1001];
int a = 1001;
void selectSort(int *array, int a){
	
	int i, j, tmp;
	for(i = 0; i < testcase; i++){
		for(j = i; j < testcase; j++)
		if(array[i] > array[j]){
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}	
	}
}

int main(void){
	
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		scanf("%d",&array[i]);
	}
	selectSort(array, a);
	for(int j = 0; j < testcase; j++){
		printf("%d\n",array[j]);
	}
	return 0;
}
