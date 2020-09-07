/** 5052 전화번호 목록
 * 문자열
 * 1.사전순으로 정렬한다
 * 2.j+1번쨰 문자열에 j번째 문자열이 포함되는지 확인한다.
 * 3.포함되어있으면 0번인덱스를 반환 + !nops 이다.
 * 4.리스트 크기 - 1 만큼 반복한다.
 */
#include <bits/stdc++.h>
using namespace std;

int t, n;
void solve() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<string> phone_list;
        for (int j = 0; j < n; j++) {
            string num;
            cin >> num;
            phone_list.push_back(num);
        }
        sort(phone_list.begin(),phone_list.end());
        bool isConsistent = true;
        for (int j = 0; j < phone_list.size()-1; j++) {
            int cur = phone_list[j].size();
            int nxt = phone_list[j+1].size();
            if(cur < nxt) {
                if(phone_list[j+1].find(phone_list[j]) == 0 && phone_list[j+1].find(phone_list[j]) != string::npos) {
                    isConsistent = false;
                    break;
                }
            }
        }
        if(isConsistent) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}