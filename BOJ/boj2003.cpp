#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[10001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int s=0, e=0;
    int sum = 0;
    int ans = 0;
    while(1) {
        if(s != n) {
            if(sum >= m) {
                sum -= arr[e++];
            } else if(sum < m){
                sum += arr[s++];
            }
            if(sum == m) ans++;
        } else if(e != n) {
            sum -= arr[e++];
            if(sum == m) ans++;
        } else {
            break;
        }
    }
    cout << ans;

    return 0;
}