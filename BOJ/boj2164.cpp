#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n; 
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while (q.size() > 1)
    {
        //버린다
        q.pop();
        //맨뒤로 보낸다
        int send = q.front();
        q.pop();
        q.push(send);
    }
    cout << q.front();

    return 0;
}