#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> v;
    int N, sum = 0;
    for(int i = 0; i < 9; i++) {
        cin >> N;
        sum += N;
        v.push_back(N);
    }
    int a, b;
    for(int i = 0; i < 9; i++) {
        for(int j = i; j < 9; j++) {
            if(i!=j && sum - (v[i] + v[j]) == 100) {
                a = v[i]; b = v[j];
            }
        }
    }
    vector<int> seven;
    for(int i = 0; i < 9; i++) {
        if(v[i]==a) {
        } else if(v[i]==b) {
        } else {
            seven.push_back(v[i]);
        }
    }
    sort(seven.begin(),seven.end());
    for (int i = 0; i < seven.size(); i++)
    {
        cout << seven[i] << "\n";
    }
    
    return 0;
}