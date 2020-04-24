#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans, tmp = 1;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    stack<char> s;
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') 
        {
            tmp *= 2;
            s.push(str[i]);
        } 
        else if(str[i] == '[') 
        {
            tmp *= 3;
            s.push(str[i]);
        }
        else if(str[i] == ')') 
        {
            if(str[i-1] == '(') ans += tmp;
            if(s.empty()) {cout << "0\n"; return 0;}
            if(s.top() == '(') s.pop();
            
            tmp /= 2;
        }
        else if(str[i] == ']') 
        {
            if(str[i-1] == '[') ans += tmp;
            if(s.empty()) {cout << "0\n"; return 0;}
            if(s.top() == '[') s.pop();
            
            tmp /= 3;
        }
    }

    if(s.empty()) {
        cout << ans;
    } else {
        cout << "0";
    }

    return 0;
}