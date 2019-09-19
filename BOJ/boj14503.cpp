// 14503 - 로봇 청소기 
#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX 50

using namespace std; 

typedef struct{
	int y, x;

}Dir;
Dir moveDir[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int room[MAX][MAX];
int N, M, clean = 0;
int initX, initY, initD;


void robot(int cx, int cy, int cd) {
	
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(cx,cy), cd));
	
	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		
        // 빈 공간이면 청소한다
		if(room[y][x] == 0) {
			room[y][x] = 2;
			clean++;
		}
		q.pop();
		
		bool isClean = false;
		
		// 4방향 청소하기  
		for(int i = 0; i < 4; i++) {
			int nd = (d + (3 - i)) % 4; //d - 1 < 0 ? 3 : d - 1;
			int nx = x + moveDir[nd].x;
			int ny = y + moveDir[nd].y;
			
			if(0 <= nx && 0 <= ny && nx < M && ny < N) 
			{
				// 방향 전환 
				if(!room[ny][nx])
				{
					q.push(make_pair(make_pair(ny,nx), nd));
					isClean = true;
					break;
				}
			}
		}
		
		// 4 방향 청소 되어있는 경우 
		if(!isClean) {
			// 한 칸 후진 
			int nx = x - moveDir[d].x;
			int ny = y - moveDir[d].y;
			if((0 <= nx && 0 <= ny && nx < M && ny < N) && room[ny][nx] != 1) {
				q.push(make_pair(make_pair(ny,nx), d));
			} else {
				break;
			}
		} 
	}
}


int main(void) {
	
	
	scanf("%d %d",&N ,&M);
	scanf("%d %d %d",&initX ,&initY ,&initD);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d",&room[i][j]);
		}
	}
	
	robot(initX, initY, initD);

	printf("%d\n",clean);
	
	return 0;
}