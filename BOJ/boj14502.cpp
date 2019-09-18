// 14502 - 연구실
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 8

using namespace std;

int moveY[4] = {0,0,1,-1};
int moveX[4] = {1,-1,0,0};
int lab[MAX][MAX];
int tmplab[MAX][MAX];
int N, M, result;

void bfs(void) {
	
	// 바이러스가 퍼진 연구실 
	int spreadVirus[MAX][MAX];
	
	queue<pair<int, int> > q;
	
	// 연구실 복사 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			spreadVirus[i][j] = tmplab[i][j];
		}
	}
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			// 만약 바이러스일 경우 큐에 넣는다 
			if(spreadVirus[i][j] == 2) {
				q.push(make_pair(i,j));	
			}
		}
	}
	
	while(!q.empty()) {
		int y = q.front().first; 
		int x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int ny = y + moveY[i];
			int nx = x + moveX[i];
			if(0 <= ny && 0 <= nx && ny < N && nx < M){ // 범위 내  
				// 연구실에 빈칸일 경우 바이러스를 퍼트린다 
				if(spreadVirus[ny][nx] == 0) {
					spreadVirus[ny][nx] = 2;
					q.push(make_pair(ny,nx));
				}	
			}
		}
	}
	
	// 빈칸 제거
	int safe = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(spreadVirus[i][j] == 0) {
				safe++;
			}
		}
	}
	result = max(result, safe);
}

void makeWall(int cnt) {
	// 벽이 3개 세워지면 
	if(cnt == 3) {
		// 바이러스 확산 시킨다 
		bfs();
		return;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			// 복사된 연구실에 빈칸일 경우 
			if(tmplab[i][j] == 0){
				tmplab[i][j] = 1;
				makeWall(cnt + 1);
				tmplab[i][j] = 0;
			}
		}
	}
}

int main(void) {
	// N, M 입력 
	cin >> N >> M;
	
	// 연구실 상황 입력 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> lab[i][j];
		}	
	}
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			// 연구실에 빈칸일 경우 
			if(lab[i][j] == 0) {
				// 연구실 복사 
				for(int r = 0; r < N; r++){
					for(int s = 0; s < M; s++){
						tmplab[r][s] = lab[r][s];
					}	
				}
				// 복사된 연구실에 벽을 세운다 
				tmplab[i][j] = 1;
				makeWall(1);
				// 벽을 다시 허문다 
				tmplab[i][j] = 0;
			}
		}	
	}
	
	cout << result;
	
	return 0;
}