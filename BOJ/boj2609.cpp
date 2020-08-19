/** 2609 gcd lcm
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    if(a < b) {
        a^=b^=a^=b;
    }
    cout << gcd(a,b) <<"\n";
    cout << (a*b)/gcd(a,b) <<"\n";
    return 0;
}