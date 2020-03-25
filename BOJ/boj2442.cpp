#include <bits/stdc++.h>
using namespace std;
void star1(int N) {
    for (int i = 1; i <= N; i++)
    {
        if(i < N) {
            for (int j = i; j < N; j++)
            {
                cout << " ";
            }
        }
        for (int j = 1; j < i*2; j++)
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