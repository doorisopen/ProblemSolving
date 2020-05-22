#include <bits/stdc++.h>
using namespace std;
#define ll long long

int testcase, n, m;
char board[1001][1001];
int fire_visit[1001][1001];
int people_visit[1001][1001];
queue<pair<int, int> > fire;
queue<pair<int, int> > people;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


void fire_bfs() {

    while (!fire.empty()) {
        auto cur = fire.front(); fire.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= m || nx < 0 || ny >= n || ny < 0) continue;
            if(board[nx][ny] == '#') continue;
            if(fire_visit[nx][ny] >= 0) continue;

            fire_visit[nx][ny] = fire_visit[x][y] + 1;
            fire.push({nx, ny});
        }
    }
    
}
void people_bfs() {
    while (!people.empty()) {
        auto cur = people.front(); people.pop();
        int x = cur.first;
        int y = cur.second;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= m || nx < 0 || ny >= n || ny < 0) {
                cout << people_visit[x][y] + 1 << "\n";
                return;
            }
            if(board[nx][ny] == '#') continue;
            if(fire_visit[nx][ny] != -1 && people_visit[x][y] + 1 >= fire_visit[nx][ny]) continue;
            if(people_visit[nx][ny] >= 0) continue;
            
            people_visit[nx][ny] = people_visit[x][y] + 1;
            people.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> testcase;
    while (testcase--) {
        //input
        cin >> n >> m;

        //init
        memset(board, 0, sizeof(board));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fire_visit[i][j] = -1;
                people_visit[i][j] = -1;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if(board[i][j] == '*') {
                    fire.push({i,j});
                    fire_visit[i][j] = 0;
                }
                if(board[i][j] == '@') {
                    people.push({i,j});
                    people_visit[i][j] = 0;
                }
            }
        }
        //fire bfs
        fire_bfs();
        
        //people bfs
        people_bfs();

        //init
        while(!fire.empty()){fire.pop();}
        while(!people.empty()){people.pop();}
    }
    return 0;
}

void printAll() {
    cout << "=============\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << fire_visit[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "=============\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << people_visit[i][j] << "  ";
        }
        cout << "\n";
    }
}