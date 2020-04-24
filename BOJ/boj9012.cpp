#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        stack<char> s;
        bool check = false;
        string str;
        cin >> str;

        for(int j = 0; j < str.length(); j++) {
            if(str[j] == '(') {
                s.push('(');
                // cout << s.size() << "\n";
            } else if(str[j] == ')') {
                if(!s.empty()) {
                    s.pop();
                    check = true;
                } else {
                    check = false;
                    break;
                }
            }
        }
        if(s.size() == 0 && check) {
            cout << "YES\n";
        } else if(s.size() > 0 || !check) {
            cout << "NO\n";
        }
    }
    return 0;
}