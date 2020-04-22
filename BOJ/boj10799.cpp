#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str;
    cin >> str;

    stack<char> s;
    int close = 0;
    int sum = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            s.pop();
            // cut
            if(str[i-1] == '(') {
                sum += close;
                close = 0;
                sum += s.size();
            } else {
                close++;
            }
        }
    }
    cout << sum + close;

    return 0;
}