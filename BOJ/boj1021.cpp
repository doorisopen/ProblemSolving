#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, count = 0;
    cin >> n >> m;
    
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int num, idx;
        cin >> num;
        
        //find index
        for(int j = 0; j < dq.size(); ++j) {
            if(dq[j] == num) {
                idx = j;
                break;
            }
        }
        // <-- 연산
        if(idx < dq.size() - idx) {
            while (1)
            {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                ++count;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        // --> 연산 
        else {
            while (1)
            {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                ++count;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << count;
    return 0;
}