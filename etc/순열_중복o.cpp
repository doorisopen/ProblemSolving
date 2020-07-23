#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
#define MAX 10000001

int n = 5, m = 3; // n: 원소 개수, m: 순열 개수
int arr[MAX];

void duplicate_permutation(int d) {
    if(d == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[d] = i;
        duplicate_permutation(d+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    duplicate_permutation(0);

    return 0;
}