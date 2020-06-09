#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int n = 4, m = 3; // n: 원소 개수, m: 순열 개수
vector<int> arr;
bool visit[10];

void combination(int d, int a) {
    if(d == m) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for (int i = a; i <= n; i++) {
        if(!visit[i]) {
            arr.push_back(i);
            visit[i] = true;
            combination(d+1, i);
            arr.pop_back();          
            visit[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    combination(0,1);

    return 0;
}