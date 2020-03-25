#include <bits/stdc++.h>
using namespace std;

bool desc(int a, int b){ return a > b; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    int c[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for(int i = 1; i <= 10; i++) {
        cin >> a >> b;
        reverse(c+a-1, c+b);
    }

    for(int i = 0; i < 20; i++) {
        cout << c[i] << " ";
    }

    return 0;
}