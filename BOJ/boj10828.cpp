// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

const int mx = 1000005;
int dat[mx];
int pos = 0;

void push(int x) {dat[pos++] = x;}
void pop() {
    if(pos > 0) {
        cout << dat[pos-1] << "\n";
        pos--;
    } else {
        cout << "-1\n";
    }
}
int top() {
    if(pos-1 != -1) {
        return dat[pos-1];
    } else {
        return -1;
    }
}
int size() {
    if(pos == 0) {
        return 0;
    } else {
        return pos;
    }
}
int empty() {
    if(pos == 0) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "push") {
            int num;
            cin >> num;
            push(num);
        } else if(str == "pop") {
            pop();
        } else if(str == "size") {
            cout << size() << "\n";
        } else if(str == "top") {
            cout << top() << "\n";
        } else if(str == "empty") {
            cout << empty() << "\n";
        }
    }

    return 0;
}