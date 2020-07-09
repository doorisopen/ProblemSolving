#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
int n;
char board[64][64];

bool isOne(int N, int x, int y) {
    for (int i = x; i < N+x; i++) {
        for (int j = y; j < N+y; j++) {
            if(board[i][j] == '0') {
                return false;
            }
        }   
    }
    return true;
}
bool isZero(int N, int x, int y) {
    for (int i = x; i < N+x; i++) {
        for (int j = y; j < N+y; j++) {
            if(board[i][j] == '1') {
                return false;
            }
        }   
    }
    return true;
}
string quadTree(int N, int x, int y) {
    if(isOne(N,x,y)) {
        return "1";
    }
    if(isZero(N,x,y)) {
        return "0";
    }

    return "(" + quadTree(N/2, x, y) 
    + quadTree(N/2, x, y+N/2)  
    + quadTree(N/2, x+N/2, y)
    + quadTree(N/2, x+N/2, y+N/2) + ")";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << quadTree(n,0,0);

    return 0;
}