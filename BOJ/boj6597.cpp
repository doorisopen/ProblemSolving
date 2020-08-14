#include <bits/stdc++.h>
using namespace std;

void postOrder(string pre, string in) {
    if(!pre.length()) return;

    int n = pre.size();
    char root = pre[0];
    int left = find(in.begin(),in.end(),root) - in.begin();
    int right = n - left - 1;
    postOrder(pre.substr(1,left), in.substr(0,left));
    postOrder(pre.substr(left+1,n), in.substr(left+1,n));
    cout << root;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (!cin.eof()) {
        string in, pre;
        cin >> pre >> in;

        postOrder(pre, in);
        cout << "\n";
    }
    return 0;
}