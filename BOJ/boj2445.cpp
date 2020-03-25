#include <bits/stdc++.h>
using namespace std;
void star1(int N) {
    // top
    for (int i = 1; i < N; i++)
    {
        // left
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        // blank
        for (int k = (N*2)-(i*2); k > 0; k--)
        {
            cout << " ";
        }
        // right
        for(int s = i; s > 0; s--) {
            cout << "*";  
        }
        cout << "\n";
    }
    // bottom 
    for (int i = N; i > 0; i--)
    {
        // left
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        // blank
        for (int k = 0; k < 2*(N-i); k++)
        {
            cout << " ";
        }
        // right
        for(int s = i; s > 0; s--) {
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