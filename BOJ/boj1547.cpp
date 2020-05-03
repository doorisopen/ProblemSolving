#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t, x, y, tmp = 0;
    int cup[4];
    cup[1] = 1;
    cup[2] = 2;
    cup[3] = 3;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        tmp = cup[x];
        cup[x] = cup[y];
        cup[y] = tmp;
    }
    for (int j = 1; j <= 3; j++){
        if(cup[j] == 1) {
            cout << j;
        }
    }

    return 0;
}