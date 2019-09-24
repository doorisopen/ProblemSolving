// 16927 - 배열 돌리기1 

#include <stdio.h>
#include <algorithm>
#define MAX 301
using namespace std;


int N, M, R;
int arr[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void printArray() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	} 
}


bool isRange(int x, int y, int group) {
	
	return (x >= group && y >= group && x < N - group && y < M - group);
}

void rotateArray(int group) {
	
	for(int n = 0; n < group; n++) {
		int tmp = arr[n][n];
		int x = n;
		int y = n;
		int moveDir = 0;
		int moveCnt = 0;
		
		
		while(moveCnt < 4) {
			int nx = x + dx[moveDir];
			int ny = y + dy[moveDir];
			
			if(isRange(nx, ny, n)) {
				arr[x][y] = arr[nx][ny];
				x = nx;
				y = ny;
			} else {
				moveDir = (moveDir + 1) % 4;
				moveCnt++;
			}
			
		}
		arr[n + 1][n] = tmp;
	}
	
}

int main(void) {
	
	
	scanf("%d %d %d",&N ,&M ,&R);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d",&arr[i][j]);
		}	
	}
	int group = min(N, M) / 2;
	
	while(R--) {
		rotateArray(group);
	}
	
	// 출력 
	printArray();
	
}
