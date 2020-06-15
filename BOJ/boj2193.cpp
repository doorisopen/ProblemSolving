#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
int n;
ll dp[100];

ll solve(int num) {
    if(num == 1) return 1;
    if(num == 2) return 1;
    if(dp[num] != 0) return dp[num];
    return dp[num] = solve(num-1) + solve(num-2);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n;
    cout << solve(n);

    return 0;
}