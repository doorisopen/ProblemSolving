#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, m, n, k;
int farm[51][51]={0};
int dx[5] = {-1,1,0,0};
int dy[5] = {0,0,-1,1};

void prinfFarm() {
    cout << "=========\n";
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            cout << farm[a][b] << " ";
        }
        cout << "\n";
    }
}

void solve(int c, int r) {

    queue<pair<int, int> > q;
    q.push(make_pair(c, r));
    farm[c][r] += 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < n && nx >= 0 && ny < m && ny >= 0 && farm[nx][ny] == 1) {
                farm[nx][ny] += 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {   //가로, 세로, 배추 개수
        cin >> m >> n >> k;
        
        //farm input
        for (int j = 0; j < k; j++) {
            int c, r;
            cin >> r >> c;
            farm[c][r] = 1;
        }

        //search
        int bug = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if(farm[a][b] == 1) {
                    ++bug;
                    solve(a, b);
                }
            }    
        }
        // prinfFarm();
        cout << bug << "\n";
        int farm[51][51];
        memset(farm, 0, sizeof(farm));
        // fill(&farm[0][0], &farm[51][51], 0); ??
    }
    
    return 0;
}