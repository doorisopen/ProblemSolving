/* 
 * 17142 연구소3
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int buffer[51][51];
int board[51][51];
int visit[51][51];
int setCheck[11];
vector<pi> virus;
vector<pi> selected;
int n,m,area,result=999999;
void p() {
	cout << "------board------visit------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << " | ";
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}
void spread() {
	queue<pi> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(visit[i][j]==0) {
				q.push({i,j});
			}
		}
	}
	int mxDay = 0, infectArea = 0;
	while(!q.empty()) {	
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx>=n||ny>=n||nx<0||ny<0) continue;
			if(board[nx][ny]==1||visit[nx][ny]!=-1) continue;
			visit[nx][ny] = visit[x][y] + 1;
			q.push({nx,ny});
			if(board[nx][ny]==0) {//감염지역 확인
				infectArea++;
				mxDay = visit[nx][ny];
			}
		}
	}
	if(infectArea==area&&result>mxDay) {
		result = mxDay;
	}
}
void setVirus(int count, int idx) {
	if(count == m) {
		//map setting
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = buffer[i][j];
				visit[i][j] = -1;
			}
		}
		for (int i = 0; i < selected.size(); i++) {
			board[selected[i].first][selected[i].second] = 3;
			visit[selected[i].first][selected[i].second] = 0;
		}
		spread();
	}
	for (int i = idx; i < virus.size(); i++) {
		if(!setCheck[i]) {
			setCheck[i] = 1;
			selected.push_back({virus[i].first,virus[i].second});
			setVirus(count+1,i);
			setCheck[i] = 0;
			selected.pop_back();
		}
	}
}
void solution() {
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> buffer[i][j];
			if(buffer[i][j] == 2) {
				virus.push_back({i,j});
			}
			if(buffer[i][j] == 0) {
				area++;
			}
		}	
	}
	setVirus(0,0);
	if(result == 999999) result = -1;
	cout << result << "\n";
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}