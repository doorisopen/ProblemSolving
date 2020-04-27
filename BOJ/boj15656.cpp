#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005
int n, m;
int check[MAX];
int tmp[MAX];
vector<int> arr;

void solve(int d) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        tmp[d] = arr[i];
        solve(d+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    int num;
    
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    solve(0);

    return 0;
}