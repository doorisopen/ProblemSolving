// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

const int mx = 1000005;
int dat[mx];
int head = 0, tail = 0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    if(head == tail) {
        cout << -1 << "\n";
    } else {
        cout << dat[head++] << "\n";
    }
}

int front() {
    if(head == tail) return -1;
    return dat[head];
}
int back() {
    if(head == tail) return -1;
    return dat[tail-1];
}
int size() {
    return tail-head;
}
int empty() {
    if(head == tail) return 1;
    else return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s == "push") {
            int a;
            cin >> a;
            push(a);
        } else if(s == "pop") {
            pop();
        } else if(s == "size") {
            cout << size() << "\n";
        } else if(s == "empty") {
            cout << empty() << "\n";
        } else if(s == "front") {
            cout << front() << "\n";
        } else if(s == "back") {
            cout << back() << "\n";
        }
    }

    return 0;
}