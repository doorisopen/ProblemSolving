#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;
    // 예외상황을 처리해줘야하는 문제
    if(a > b) {
        swap(a, b);
    }
    if(a != b) {
        cout << b-a-1 << "\n";
        for(long long i = a+1; i < b; i++) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}