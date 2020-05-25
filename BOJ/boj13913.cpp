#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005

int n, k;
int visit[MAX];
int check[MAX];
stack<int> s;
queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;

    if(n == k) {
        cout << 0 << "\n" << k;
        return 0;
    }

    fill(visit, visit+MAX, -1);
    visit[n] = 0;
    check[n] = n;
    q.push(n);
    
    while (visit[k] == -1) {
        int cur = q.front(); q.pop();
        for(int next : {cur-1, cur+1, cur*2}) {
            if(next < 0 || next > 100000) continue;
            if(visit[next] != -1) continue;

            visit[next] = visit[cur] + 1;
            check[next] = cur;
            q.push(next);
        }
    }
    
    cout << visit[k] << "\n";
    
    s.push(k);
    int now = check[k];
    while (check[now] != now) {
        s.push(now);
        now = check[now];
    }
    s.push(now);
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}