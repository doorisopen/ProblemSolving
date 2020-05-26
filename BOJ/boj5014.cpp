#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f,s,g,u,d;
int board[1000005];
int visit[1000005];
queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;
    memset(visit, -1, sizeof(visit));
    visit[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == g) break;
        for(int next : {cur+u, cur-d}) {
            if(next < 1 || next > f) continue;
            if(visit[next] != -1) continue;

            visit[next] = visit[cur] + 1;
            q.push(next);
        }
    }
    
    if(visit[g] == -1) {
        cout << "use the stairs\n";
    } else {
        cout << visit[g];
    }
    
    return 0;
}