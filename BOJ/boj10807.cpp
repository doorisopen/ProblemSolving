#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, num, findNum;
    vector<int> v;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> findNum;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(findNum == v[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}