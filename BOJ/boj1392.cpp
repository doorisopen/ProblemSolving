/** 1392 노래악보
 * 단순 구현
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q, t = 0;
    int arr[10001] = {0};
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            arr[t++]=i;
        }
    }
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        cout << arr[num] << "\n";
    }
    return 0;
}
