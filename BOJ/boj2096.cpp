#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2096
#define ll long long

int tmpMax[3], tmpMin[3], maxDp[3], minDp[3];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> tmpMax[j];
            tmpMin[j] = tmpMax[j];
            tmpMax[j] += max(maxDp[1], (j==1) ? max(maxDp[0], maxDp[2]) : maxDp[j]);
            tmpMin[j] += min(minDp[1], (j==1) ? min(minDp[0], minDp[2]) : minDp[j]);
        }
        memcpy(maxDp, tmpMax, sizeof(int)*3);
        memcpy(minDp, tmpMin, sizeof(int)*3);
    }
    sort(maxDp, maxDp+3);
    sort(minDp, minDp+3);
    cout << maxDp[2] << " " << minDp[0];
    return 0;
}