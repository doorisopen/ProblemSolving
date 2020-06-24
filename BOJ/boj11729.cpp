#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
queue<pi> q;
int n;

void hanoi(int num, int from, int tmp, int to) {
    if(num == 1) {
        q.push({from, to});
    }
    else {
        hanoi(num-1, from, to, tmp);
        q.push({from, to});
        hanoi(num-1, tmp, from, to);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    hanoi(n,1,2,3);

    cout << q.size() << "\n";
    while (!q.empty()) {
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }    
    return 0;
}