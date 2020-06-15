#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 2000005;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

vector<pi> board[20005];
priority_queue<pi> pq;
int d[300005];  // 최단거리 (최소 비용)
int V,E,s,u,v,w;
//정점, 간선, 시작점, u->v, 가중치

void solve(int start) {
    d[start] = 0;
    pq.push({0,start});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int dist = -cur.first;
        int current = cur.second;
        if(d[current] < dist) continue;
        for (int i = 0; i < board[current].size(); i++) {
            int next = board[current][i].first;
            int nextDist = dist + board[current][i].second;
            if(nextDist < d[next]) {
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> V >> E;
    cin >> s;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        board[u].push_back(make_pair(v,w));
    }
    //init
    fill(d,d+300005,INF);
    
    //search
    solve(s);

    //result
    for (int i = 1; i <= V; i++) {
        if(d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << "\n";
        }
    }
    return 0;
}