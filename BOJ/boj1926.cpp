#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int mymap[501][501];
int group[501][501];
int dx[5] = {-1,1,0,0};//북남동서
int dy[5] = {0,0,-1,1};
bool isNew = false;

void solve(int c, int r, int cnt) {

    queue<pair<int, int> > q;
    q.push(make_pair(c,r));
    group[c][r] = cnt;
    while (!q.empty())
    {    
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //4방향
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < n && ny < m && nx >= 0 && ny >= 0) {
                if(mymap[nx][ny] == 1 && group[nx][ny] == 0) {
                    group[nx][ny] = cnt;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mymap[i][j];
        }
    }
    
    int paintCnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(group[i][j] == 0 && mymap[i][j] == 1) {
                solve(i, j, ++paintCnt);
            }
        }
    }
    cout << paintCnt << "\n";
    int res[501*501] = {0,};
    int len = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(group[i][j] != 0) {
                res[group[i][j]] += 1;
            }
        }
    }
    for (int i = 1; i <= paintCnt; i++){
        len = max(len, res[i]);
    }
   
    cout << len;
    return 0;
}