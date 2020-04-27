#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000001

bool selected[MAX];
int num[MAX];
int n,m;

void solve(int i) {
    if(i == m) {
        for (int j = 0; j < m; j++)
        {
            cout << num[j] << " ";
        }
        cout << "\n";
        return;
    }

    for (int a = 1; a <= n; a++)
    {
        num[i] = a;
        solve(i+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    solve(0);
    return 0;
}