#include <stdio.h>
#include <queue>
using namespace std;

bool a[101][101];


int main(void){
	int N,M,num;
	scanf("%d %d",&N ,&M);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d",&num);
			if( num == 1){
				a[i][j] = true;	
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%d", a[i][j]);
		}
		printf("\n");	
	}
	
	return 0;
}
