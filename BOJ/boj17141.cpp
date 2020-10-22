/* 
 * 17141 연구소2
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
int n,m,day=999999;

void p() {
	cout << "-----board----------visit-----\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cout << board[i][j] << " ";
		}	
		cout << " | ";
		for (int j = 0; j < n; j++){
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
}
void spread() {
	queue<pi> q;
	
	//virus input
	for (int i = 0; i < selected.size(); i++) {
		int x = selected[i].first;
		int y = selected[i].second;
		board[x][y] = 3;
		visit[x][y] = 1;
		q.push({x,y});
	}

	//spread
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx>=n||ny>=n||nx<0||ny<0) continue;
			if(board[nx][ny]||visit[nx][ny]) continue;
			visit[nx][ny] = visit[x][y] + 1;
			board[nx][ny] = 2;
			q.push({nx,ny});
		}
	}

	int dayCount = 0;
	bool isFill = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(board[i][j] == 0) {
				isFill = false;
				break;
			}
			dayCount = max(dayCount, visit[i][j]);
		}
		if(!isFill) break;
	}
	if(!isFill) {
		dayCount = 999999;
	}
	day = min(day, dayCount);
}
void setVirus(int count, int idx) {
	if(count == m) {
		//map setting
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				board[i][j] = buffer[i][j];
				visit[i][j] = 0;
			}
		}
		//start
		spread();
	}
	for (int i = idx; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		if(!setCheck[i]) {
			setCheck[i] = 1;
			selected.push_back({x,y});
			setVirus(count+1, i);
			setCheck[i] = 0;
			selected.pop_back();
		}
	}
}
void solution() {
	//input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> buffer[i][j];
			if(buffer[i][j] == 2) {
				buffer[i][j] = 0;
				virus.push_back({i,j});
			}
		}		
	}
	setVirus(0,0);
	if(day==999999) {
		cout << "-1\n";
	} else {
		cout << day-1;
	}
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}