#include <bits/stdc++.h>

using namespace std;
#define ll long long
int l, x, y, xx, yy;
int visit[301][301];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        cin >> l;
        cin >> x >> y;
        cin >> xx >> yy;
        int tmp = 9999, cnt = 0;
        if (x == xx && y == yy) {
            cout << 0 << "\n";
            continue;
        }
        
        queue<pair<int, int> > q;
        q.push({x,y});

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if(cur.first == xx && cur.second == yy) {
                cout << visit[xx][yy] << "\n";
            }
            for (int i = 0; i < 8; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(visit[nx][ny] > 0) continue;
                
                visit[nx][ny] = visit[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }       
        }
        
        
        //init
        if(!q.empty()) {
            while (!q.empty()) {
                q.pop();
            }            
        }
        memset(visit, 0, sizeof(visit));
    }
    

    return 0;
}