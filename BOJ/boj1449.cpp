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
    int N, L, cnt = 0;
    cin >> N >> L;
    int fix[100001];
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        fix[num] = -1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int cur = v[i];
        if(fix[cur] == -1) {
            cnt++;
            for(int j = cur; j < cur+L; j++) {
                fix[j] = 2;
            }
        }
    }
    cout << cnt;
    return 0;
}