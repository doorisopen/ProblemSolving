#include <bits/stdc++.h>
using namespace std;
void star1(int N) {
for (int i = N; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    star1(N);
    
    return 0;
}