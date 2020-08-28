/** 1946 신입 사원
 * 동적계획법
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<pi> v;
        int people;
        cin >> people;
        for (int j = 0; j < people; j++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int bound = v[0].second;
        for (int j = 1; j < v.size(); j++) {
            if(bound < v[j].second) {//bound보다 순위가 낮으면 탈락
                people--;
            }
            bound = min(bound, v[j].second);//더 높은 순위로 업데이트
        }
        cout << people << "\n";
    }
    
    return 0;
}
