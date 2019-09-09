// 2178 - 미로 탐색
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

// 아래, 오른쪽, 위 
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
 
int d[101][101];
int c[101][101];
int N, M;

void bfs(int x, int y) {
	c[x][y] = 1;
	queue<pair<int,int> > q;
	d[x][y] = 0;
	q.push(make_pair(x, y));
	pair<int, int> frt;
	int nx, ny;
	while(!q.empty()){
		frt = q.front();
		nx = frt.first, ny = frt.second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int mx = nx + dx[i], my = ny + dy[i];
			
			if(d[mx][my] == 1) {
				c[mx][my] = c[nx][ny] + 1;
				d[mx][my] = 0;
				q.push(make_pair(mx, my));	
			}
		}
	}
}


int main(void) {
	
	int num;
	scanf("%d %d",&N ,&M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%1d",&num);
			d[i][j] = num;
		}
	}
	bfs(1, 1);
	printf("%d",c[N][M]);
	return 0;
}
