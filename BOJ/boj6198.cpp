#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int building[80005];
/** n = 6
 *  i = 0 1 2 3  4 5
 *     10 3 7 4 12 2
 * sum= 0 1 2 4  4 5  
 */
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    ll sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> building[i];
    }

    for(int i = 0; i < n; i++) {
        // 스택이 비어있지 않고 스택의 Top이 i번째 빌딩보다 작을때
        while (!s.empty() && s.top() <= building[i]) {
            s.pop();
        }
        s.push(building[i]);
        // i번째 빌딩을 제외한 다른 빌딩들이 볼 수 있기 때문에 size - 1
        sum += s.size() - 1;
    }
    cout << sum;
    
    return 0;
}