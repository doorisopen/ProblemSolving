// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long

const int mx = 1000005;
int dat[2*mx+1];
int head = mx, tail = mx;

void push_front(int x) { dat[--head] = x; }
void push_back(int x) { dat[tail++] = x; }
int pop_front() { 
    if(head == tail) {
        return -1;
    } else {
        return dat[head++];
    }
}
int pop_back() {
    if(head == tail) {
        return -1;
    } else {
        int back = dat[tail-1];
        tail--;
        return back;
    }
}
int front() {
    if(head == tail) {
        return -1;
    } else {
        return dat[head];
    }
}
int back() {
    if(head == tail) {
        return -1;
    } else {
        return dat[tail-1];
    }
}
int empty() {
    if(head == tail) {
        return 1;
    } else {
        return 0;
    }
}
int size() {
    return tail-head;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> s;
        if(s == "push_front") {
            cin >> a;
            push_front(a);
        } else if(s == "push_back") {
            cin >> a;
            push_back(a);
        } else if(s == "pop_front") {
            cout << pop_front() << "\n";
        } else if(s == "pop_back") {
            cout << pop_back() << "\n";
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