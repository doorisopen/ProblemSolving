#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
int n;
char board[2000][2000];
void solve(int d, int x, int y) {
    if(d == 1) {
        board[x][y] = '*';        
        return;
    }
    d /= 2;
    solve(d,x,y);
    solve(d,x+d,y);
    solve(d,x,y+d);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n;
    n = 1 << n;
    
    //init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }
    
    solve(n,0,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}