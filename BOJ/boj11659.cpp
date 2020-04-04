#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);
    int t, t2;
    scanf("%d %d", &t ,&t2);
    
    vector<int> v;
    v.push_back(0);
    int sum = 0;
    for(int i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);
        sum += num;
        v.push_back(sum);
    }
    int s, e;
    for(int i = 0; i < t2; i++) {
        scanf("%d %d", &s ,&e);
        printf("%d\n", v[e] - v[s-1]);
    }

    return 0;
}