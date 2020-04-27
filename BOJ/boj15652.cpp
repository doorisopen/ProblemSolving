#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

int n, m;
int a[MAX];

void solve(int s, int d) {

    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = s; i <= n; i++)
    {
        a[d] = i;
        s = i;
        solve(s, d+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    solve(1, 0);
    return 0;
}