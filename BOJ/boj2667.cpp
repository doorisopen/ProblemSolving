// 단지번호붙이기 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 좌, 우, 아래, 위 
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
int c[26][26];
int d[26][26];
vector<int> v;
int cnt = 0;
int N; 

void dfs(int x, int y) {
	
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		// 1 && 방문하지 않은 곳 
		if(d[nx][ny] && !c[nx][ny]) {
			c[nx][ny] = true;
			cnt++;
			dfs(nx, ny);
		}
	}
	
} 

int main(void) {
	int num;
	scanf("%d",&N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%1d",&num);
			d[i][j] = num;
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(d[i][j] && !c[i][j]) {
				c[i][j] = true;
				cnt++;
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n",v.size());
	for(int i = 0; i < v.size(); i++) {
		printf("%d\n",v[i]);
	}
	
	return 0;
}
