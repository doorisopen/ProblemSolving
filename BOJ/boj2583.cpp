#include <bits/stdc++.h>
using namespace std;
#define ll long long

int m, n, k, ans;
int board[101][101];
int visit[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector<int> result;

void bfs(int r, int c) {
    queue<pair<int, int> > q;
    q.push({r,c});
    ans = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dy[i];
            int nc = cur.second + dx[i];

            //범위를 벗어나면
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (board[nr][nc] == 1) continue;
            if (visit[nr][nc] > 0) continue;
            visit[nr][nc] = 1;
            ans++;
            q.push({nr, nc});
        }
    }
    if(ans == 0) {
        result.push_back(ans+1);
    } else {
        result.push_back(ans);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //input
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int y = (m-ly)-1; y >= m-ry; y--) {
            for (int x = lx; x < rx; x++) {
                if(board[y][x] == 0) board[y][x] = 1;
            }
        }
    }


    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if(visit[y][x] == 0 && board[y][x] == 0) {
                bfs(y, x);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}