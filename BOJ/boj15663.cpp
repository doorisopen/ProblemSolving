#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
int n, m;
int arr[MAX];
vector<int> v;
bool check[MAX];

void solve(int d, int a) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    bool select[11] = {false, };
    for (int i = 0; i < v.size(); i++)
    {
        if(!select[v[i]] && !check[i]) {
            check[i] = true;
            select[v[i]] = true;
            arr[d] = v[i];

            solve(d+1, i);
            check[i] = false;
        }
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
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    solve(0, 0);

    return 0;
}