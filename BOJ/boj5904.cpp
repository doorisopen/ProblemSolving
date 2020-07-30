#include <iostream>
using namespace std;

long long n, S[100];

string solve(long long n) {
    if(n <= 3) {
        if(n == 1) return "m";
        else return "o";
    }
    long long i = 1;
    while (n > S[i]) {
        i++;
    }

    if(n <= S[i] - S[i-1]) {
        if(n - S[i-1] == 1) return "m";
        else return "o";
    }
    
    return solve(n - S[i-1] - (i+3));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // S(0 ~ 40) length 구하기
    S[0] = 3;
    for (int i = 1; i <= 40; i++) {
        S[i] = 2 * S[i-1] + (i + 3);
    }
    
    cin >> n;
    cout << solve(n);
    return 0;
}