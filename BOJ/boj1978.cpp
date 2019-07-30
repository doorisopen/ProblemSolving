// 1978 - 소수찾기

#include <stdio.h>
#include <math.h>

int a[1001];
int primeNumber = 0;
void PrimeNumberSieve() {
	// 제곱근을 확인하는 함수 
	// 초기화 
	for(int i = 2; i <= 1000; i++){
		a[i] = i;
	} 
	
	for(int i = 2; i <= 1000; i++){
		if(a[i] == 0) continue;
		for(int j = i + i; j <= 1000; j += i ){
			a[j] = 0;
		}
	}
}

int main(void) {
	
	int testcase;
	int num;
	
	PrimeNumberSieve();
	
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		scanf("%d",&num);
		if(a[num] != 0){
			primeNumber++;
		}
	}
	printf("%d",primeNumber);
	
	return 0;
}

