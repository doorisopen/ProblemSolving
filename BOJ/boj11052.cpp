// 11052 - 카드 구매하기 
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[1001];
int p[1001];
int main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&p[i]);
	}
	d[1] = p[1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			d[i] = max(d[i], d[i-j] + p[j]);
		}
	}
	printf("%d",d[n]);
	
	return 0;
} 
