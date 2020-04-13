#include <bits/stdc++.h>
using namespace std;

#define ll long long
char arr[200005];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    stack<int> s;
    
    int num, sTop = 1, idx = 0;
    bool check = true;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(sTop <= num) {
            for(int j = sTop; j <= num; j++){
                s.push(j);
                // cout << "+";
                arr[idx++] = '+';
            }
            if(s.top() == num) {
                sTop = num+1;
                s.pop();
                // cout << "-";
                arr[idx++] = '-';
            }
        } else if(s.top() == num) {
            s.pop();
            arr[idx++] = '-';
        } else {
            check = false;
        }
    }
    if(!check) {
        cout << "NO";
        return 0;
    }
    // cout << arr[idx];
    for(int i = 0; i < idx; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}