#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int n = 5, m = 5; // n: 원소 개수, m: 순열 개수
vector<int> arr;
bool visit[10];


void permutation(int d) {
    if(d == m) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        if(!visit[i]) {
            arr.push_back(a[i]);
            visit[i] = true;
            permutation(d+1);
            arr.pop_back();          
            visit[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    permutation(0);

    return 0;
}