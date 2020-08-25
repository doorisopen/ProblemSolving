/** 1644 소수의 연속합 
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int n;
int prime[4000001];
vector<int> arr;
void init() {
    for (int i = 2; i <= n; i++) {
        prime[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if(prime[i] == 0) continue;
        for (int j = i+i; j <= n; j+=i) {
            prime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if(prime[i] != 0) arr.push_back(i);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    if(n==1) {
        cout << "0";
        return 0;
    }
    init();
    int s=0, e=0, sm=0, cnt=0;
    sm += arr[e];
    while (s!=arr.size()&&e!=arr.size()) {
        if(sm == n) {
            sm -= arr[s++];
            cnt++;
        } else if(sm > n) {
            sm -= arr[s++];
        } else {
            sm += arr[++e];
        }
    }
    cout << cnt;
    return 0;
}