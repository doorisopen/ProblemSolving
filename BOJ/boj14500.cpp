// BOJ 14500 테트로미노
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
// ㅜ, ㅏ, ㅗ, ㅓ,
int hx[4][4] = {{0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,0,1}};
int hy[4][4] = {{0,1,2,1},{0,0,0,1},{0,1,2,1},{0,1,1,1}};
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
int board[501][501];
int visit[501][501];
int check[501][501];
int n, m, ans = -1;

void printMap() {
    cout << "=========\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
}
void dfs(int x, int y, int sum, int depth) {
    if(depth > 3) {
        ans = max(ans, sum);
        sum = 0;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(!visit[nx][ny]) {
            visit[nx][ny] = true;
            sum += board[nx][ny];
            dfs(nx, ny, sum, depth+1);
            sum -= board[nx][ny];
            visit[nx][ny] = false;
        }
    }
}
void dfs_h(int x, int y) {
    for (int i = 0; i < 4; i++) {
        bool isBoundary = true;
        int sum = 0;

        for (int j = 0; j < 4; j++) {
            int nx = x + hx[i][j];
            int ny = y + hy[i][j];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                isBoundary = false;
                break;
            }
            sum += board[nx][ny];
        }
        if(isBoundary) {
            ans = max(ans, sum);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }        
    }

    //search(ㅣ,ㄴ,ㅁ)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = true;
            dfs(i,j,board[i][j],1);
            visit[i][j] = false;

            //search(ㅏ)
            dfs_h(i,j);
        }
    }
    
    cout << ans;
    

    return 0;
}