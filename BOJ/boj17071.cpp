#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 500001 
int n, k;
int board[2][MAX];
int visit[2][MAX];
queue<pair<int, int> > q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    fill(visit[0], visit[0]+MAX, -1);
    fill(visit[1], visit[1]+MAX, -1);
    q.push({0, n});
    visit[0][n] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int next : {cur.second - 1, cur.second + 1, cur.second * 2}) {
            if(next < 0 || next > 500000) continue;
            if(visit[1 - cur.first][next] != -1) continue;

            visit[1 - cur.first][next] = visit[cur.first][cur.second] + 1;
            q.push({1 - cur.first, next});
        }
    }

    int ans = 9999999, t = 0;
    while (k <= 500000) {
        if(visit[t%2][k] != -1 && visit[t%2][k] <= t) ans = min(ans, t);
        k += ++t;
    }

    if(ans == 9999999) {
        cout << -1;
    } 
    else {
        cout << ans;
    }

    return 0;
}