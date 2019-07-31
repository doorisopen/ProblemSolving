// 2798 - ∫Ì∑¢¿Ë 
#include <stdio.h>

int card[100];
int N, M;

int main(void){
	int result = 0;
	scanf("%d %d",&N,&M);
	for(int i = 0; i < N; i++){
		scanf("%d",&card[i]);
	}
	
	for(int i = 0; i < N-2; i++){
		for(int j = i+1; j < N-1; j++){
			for(int k = j+1; k < N; k++){
				if(card[i] + card[j] + card[k] <= M && M - (card[i] + card[j] + card[k]) < M - result ){
					result = card[i] + card[j] + card[k];
				}
			}
		}
	}
	printf("%d", result);
	
	return 0;
}
