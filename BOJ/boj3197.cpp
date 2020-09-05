/** 3197 백조의 호수
 * bfs
 * 1.얼음녹는 지점 전처리
 * 2.백조 bfs
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int r,c,mxV = 0,ans = 999999;
char board[1501][1501];
int iceVisit[1501][1501];
int beakjoVisit[1501][1501];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int, pi> > iceQ;
queue<pi> beakjoQ;
vector<pi> beakjo;

void printBeakjo() {
    cout << "\n==========\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << beakjoVisit[i][j];          
        }
        cout << "\n";
    }
}
void printIce() {
    cout << "\n==========\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << iceVisit[i][j];          
        }
        cout << "\n";
    }
}

void iceBfs() {
    while (!iceQ.empty()) {
        auto cur = iceQ.front(); iceQ.pop();
        int val = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(iceVisit[nx][ny] == -1) {
                iceVisit[nx][ny] = val+1;
                mxV = max(mxV, iceVisit[nx][ny]);
                iceQ.push({val+1,{nx,ny}});
            }
        }
    }    
}

bool beakjoBfs(int day) {
    beakjoQ.push({beakjo[0].first, beakjo[0].second});
    beakjoVisit[beakjo[0].first][beakjo[0].second] = 1;

    while (!beakjoQ.empty()) {
        auto cur = beakjoQ.front(); beakjoQ.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(beakjoVisit[nx][ny] || iceVisit[nx][ny] > day) continue;
            if(nx == beakjo[1].first && ny == beakjo[1].second) {
                return true;
            }
            beakjoVisit[nx][ny] = 1;
            beakjoQ.push({nx,ny});
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'X') {
                iceVisit[i][j] = -1;
            }
            if(board[i][j] == 'L') {
                beakjo.push_back({i,j});
            }
            if(board[i][j] == 'L' || board[i][j] == '.') {
                iceQ.push({0,{i,j}});
            }
        }
    }
    //얼음 녹이기 bfs
    iceBfs();   
    // printIce();

    //얼음이 모두 녹는 최대 일수를 이분탐색하여
    //백조가 만나는지 확인
    int s = 0, e = mxV;
    while (s <= e) {
        //init
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                beakjoVisit[i][j] = 0;
            }
        }
        while(!beakjoQ.empty()) beakjoQ.pop();

        //binary search
        int mid = (s+e)/2;
        if(beakjoBfs(mid)) {
            ans = min(ans, mid);
            e = mid-1;
        } else {
            s = mid+1;
        }
        // printBeakjo();
    }
    cout << ans;
    return 0;
}