#include <bits/stdc++.h>
using namespace std;

#define ll long long
priority_queue<int> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, a;
    cin >> n;
    
    for(int i = 0; i < n*n; i++) {       
        cin >> a;
        if(q.size() < n) {
            q.push(-a);
        } else {
            if(-q.top() < a) {
                q.pop();
                q.push(-a);
            } else {
                continue;
            }
        }
    }
    cout << -q.top();
    
    return 0;
}