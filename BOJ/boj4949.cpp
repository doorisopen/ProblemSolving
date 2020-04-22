#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    while (str != ".")
    {
        str = "";
        bool check = true;
        stack<char> s;
        getline(cin, str);
        if(str.length() == 1 && str[0] == '.') {break;}

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[') { 
                s.push(str[i]);
            } 
            else if(str[i] == ')') {
                if(!s.empty()) {
                    if(s.top() == '(') {
                        check = true;
                        s.pop();
                    } else {
                        check = false;
                        break;
                    }
                } else {
                    check = false;
                    break;
                }
            } 
            else if(str[i] == ']') {
                if(!s.empty()) {
                    if(s.top() == '[') {
                        check = true;
                        s.pop();
                    } else {
                        check = false;
                        break;
                    }
                } else {
                    check = false;
                    break;
                }
            }
        }
        if(s.size() > 0) {check = false;}

        if(check) {cout << "yes\n";}
        else {cout << "no\n";}
    }
    return 0;
}