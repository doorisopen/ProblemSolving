#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long

/**조건
    for, while문 사용 x
*/
void solve(string str, int len) {
    if(len == -1) return;
    
    cout << str[len-1];
    solve(str, len-1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str = "hello world";

    solve(str, str.length());

    return 0;
}