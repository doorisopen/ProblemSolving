#include <bits/stdc++.h>
using namespace std;
void star1(int N) {
    // top
    for (int i = 1; i < N; i++)
    {
        // left blank
        for (int j = 0; j < i-1; j++)
        {
            cout << " ";
        }
        // star
        for (int k = (N*2)-(i*2); k >= 0; k--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    // bottom 
    for (int i = N; i > 0; i--)
    {
        // left blank
        for (int j = i-1; j > 0; j--)
        {
            cout << " ";
        }
        // star
        for (int k = 0; k <= 2*(N-i); k++)
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