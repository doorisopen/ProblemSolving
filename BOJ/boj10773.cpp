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
        pos--;
    }
}
int top() {
    return dat[pos-1];
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num != 0) {
            push(num);
        } else {
            pop();
        }
    }

    int sum = 0;
    while (pos > 0)
    {
        sum += top();
        pop();
    }
    cout << sum;

    return 0;
}