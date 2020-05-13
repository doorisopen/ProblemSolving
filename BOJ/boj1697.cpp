#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005

int n, k;
int board[MAX];
int visit[MAX];
queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    fill(visit, visit+MAX, -1);
    visit[n] = 0;
    q.push(n);

    while (visit[k] == -1) {
        int cur = q.front(); q.pop();
        for(int next : {cur-1, cur+1, cur*2}) {
            if(next < 0 || next > 100000) continue;
            if(visit[next] != -1) continue;
            visit[next] = visit[cur] + 1;
            q.push(next);
        }
    }
    cout << visit[k];
    
    return 0;
}