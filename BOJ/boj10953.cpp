#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    char b;
    int a, c;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        cout << a+c << "\n";
    }

    return 0;
}