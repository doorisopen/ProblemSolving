#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[10];
int tmp[10];
bool check[10];
int t = -1;

void solve(int d, int a) {
    if(d == 6) {
        for (int i = 0; i < 6; i++)
        {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = a; i < t; i++)
    {
        if(!check[i]) {
            check[i] = true;
            tmp[d] = arr[i];
            solve(d+1, i);
            check[i] = false;
        }
    }    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    while(t != 0) {
        cin >> t;
        if(t == 0) break;
        
        int num;
        fill(arr, arr+t, 0);
        for (int i = 0; i < t; i++)
        {
            cin >> num;
            arr[i] = num;
        }
        solve(0, 0);
        cout << "\n";
    }
    return 0;
}