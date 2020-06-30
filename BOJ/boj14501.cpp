// BOJ 14501 퇴사
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int n, total = 0;
bool check[16];
vector<pi> board[16];

void dfs(int day, int sum) {
    if(total <= sum) {
        total = sum;
    }
    for (int i = day; i <= n; i++) {
        int it = board[i][0].first;
        int ip = board[i][0].second;
        if(i + it <= (n+1) && !check[i]) {
            check[i] = true;
            dfs(i + it, sum + ip);
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        board[i].push_back({t, p});
    }

    dfs(1,0);
    cout << total;
    
    return 0;
}