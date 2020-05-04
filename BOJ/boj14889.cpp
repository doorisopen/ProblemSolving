#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, ans = 9999322;
int m[22][22];
bool selected[22];

void dfs(int d, int p) {

    if(d == n/2) {
        int a, b;
        a = b = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(selected[i] && selected[j]) {
                    a += m[i][j];
                } else if(!selected[i] && !selected[j]) {
                    b += m[i][j];
                }
            }
        }
        ans = min(ans, abs(a-b));
        return;
    }
    for (int i = p; i < n; i++)
    {
        selected[i] = true;
        dfs(d + 1, i + 1);
        selected[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //input
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    dfs(0, 1);
    cout << ans;
    return 0;
}