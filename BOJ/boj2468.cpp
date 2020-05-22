#include <iostream>
#include <queue>
using namespace std;
#define ll long long

int n, lowest=1000, highest;
int board[101][101];
int visit[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
queue<pair<int, int> > q;

void bfs(int rain, int cnt) {
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(board[nx][ny] > rain && visit[nx][ny] == 0) {
                    visit[nx][ny] = cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    // cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            board[i][j] > highest ? highest = board[i][j] : highest;
            board[i][j] < lowest ? lowest = board[i][j] : lowest;
            
        }
    }
    
    if(lowest == highest) {
        cout << 1; 
        return 0;
    }
    int ans = 0, cnt = 0;
    for(int rain = lowest; rain <= highest; rain++) {
        //init
        cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visit[i][j] = 0;
            }
        }
        //memset(visit, 0, sizeof(visit));
        //search
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if(board[x][y] > rain && visit[x][y] == 0) {
                    q.push(make_pair(x,y));
                    visit[x][y] = 1;
                    bfs(rain, cnt++);
                }
            }
        }
        //result
        ans < cnt ? ans = cnt : ans;        
    }
    cout << ans-1 << "\n";
    
    return 0;
}