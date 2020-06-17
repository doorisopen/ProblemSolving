#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int L, P, V, idx = 1;
    while(1) {
        cin >> L >> P >> V;
        if(L == 0) break;
        int ans = 0, div = 0;
        div = V/P;
        ans = L * div;
        if(V-(P*div) >= L) {
            ans += L;
        } else {
            ans += V-(P*div);
        }
        cout << "Case " << idx++ << ": " << ans << "\n";
    }
    return 0;
}