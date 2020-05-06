#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[302][302] = {0,};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, m, t, x1, y1, x2, y2, num = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }        
    }
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int tmp = 0;

        for (int i = x1; i <= x2; i++){
            for (int j = y1; j <= y2; j++){
                tmp += arr[i][j];
            }            
        }
        cout << tmp << "\n";
    }
    return 0;
}