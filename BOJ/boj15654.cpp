#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005

int n, m;
int arr[MAX];
bool check[MAX];
vector<int> v;

void solve(int d) {

    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if(!check[i]) {
            check[i] = true;
            arr[d] = v[i];
            solve(d+1);
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

    solve(0);

    return 0;
}