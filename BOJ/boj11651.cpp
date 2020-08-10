/** 11651 좌표 정렬하기 2
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

bool compare(pi n1, pi n2) {
    if(n1.second != n2.second) {
        return n1.second < n2.second ? true : false;
    } else {
        return n1.first < n2.first ? true : false;
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<pi> v;
    int n;
    cin >> n;
    while (n--) {
        int r,c;
        cin >> r >> c;
        v.push_back({r,c});
    }
    sort(v.begin(),v.end(),compare);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}