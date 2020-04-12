#include <bits/stdc++.h>
using namespace std;

/*
재귀를 이용한 숫자 찍기
N = 5
12345
1234
123
12
1
*/
void star2(int N, int step) {
    if(N == 0) return;
    if(step <= N) {
        cout << step;
        star2(N, step+1);
    } else {
        cout << "\n";
        star2(N-1, 1);
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    // cin >> N;
    star2(5, 1);
    
    return 0;
}