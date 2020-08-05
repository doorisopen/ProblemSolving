#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[500];
int dp[500][500];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, res=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }

    dp[0][0] = v[0][0];
    res = max(res, dp[0][0]);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + v[i+1][j+1]);
            if(dp[i+1][j] > dp[i+1][j+1]) {
                res = max(res, dp[i+1][j]);
            } else {
                res = max(res, dp[i+1][j+1]);
            }
        }
    }
    cout << res;
    
    return 0;
}