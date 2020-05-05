/**
 * 종만북 p.119
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MIN = -1;

// O(n)
int fastestMaxNum(vector<int>& A) {
    int N = A.size(), ret = MIN, psum = 0;
    for (int i = 0; i < N; i++)
    {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<int> arr;

    arr.push_back(-7);
    arr.push_back(4);
    arr.push_back(-3);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(-8);
    arr.push_back(3);
    arr.push_back(4);

    cout << fastestMaxNum(arr) << "\n";

    return 0;
}