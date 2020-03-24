#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    int sum = 0;
    vector<int> v;
    for(int i = 0; i < 7; i++) {
        cin >> N;
        if(N % 2 == 1) {
            sum += N;
            v.push_back(N);
        }
    }
    if(v.size() == 0) {
        cout << "-1";
        return 0;
    }
    sort(v.begin(),v.end());
    cout << sum << "\n";
    cout << v[0] << "\n";
    
    return 0;
}