#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, num;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num); 
    }
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[n-1]; 
    
    return 0;
}