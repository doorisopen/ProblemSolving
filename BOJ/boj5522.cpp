/** 5522 카드 게임
 * 단순 구현
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int num, sum = 0;
    while(!cin.eof()) {
        cin >> num;
        sum += num;
    }
    cout << sum-num;
    return 0;
}
