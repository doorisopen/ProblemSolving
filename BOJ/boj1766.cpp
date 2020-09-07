/** 1766 문제집
 * 위상정렬 + 우선순위큐
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
int dgr[32001];
int result[32001];
vector<int> arr[32001];
void search() {
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if(dgr[i] == 0) q.push(-i);
    }
    for (int i = 1; i <= n; i++) {
        if(q.empty()) {
            cout << "-1";
            return;
        }
        int cur = -q.top(); q.pop();
        result[i] = cur;
        for (int j = 0; j < arr[cur].size(); j++) {
            int nxt = arr[cur][j];
            if(--dgr[nxt] == 0) q.push(-nxt);
        }
    }
}
void solve() {
    cin >> n >> m;
    int f,s;
    for (int i = 0; i < m; i++) {
        cin >> f >> s;
        arr[f].push_back(s);
        dgr[s]++;
    }
    search();
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}