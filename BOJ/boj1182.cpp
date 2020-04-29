#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, result = 0;
int arr[21];

void solve(int sum, int idx) {
    if(idx == n && sum == m) {
        result++;
        return;
    } else if(idx == n) return;
    
    solve(sum + arr[idx], idx+1);
    solve(sum, idx+1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(0, 0);
    if(m == 0) result--;
    cout << result;
    
    return 0;
}