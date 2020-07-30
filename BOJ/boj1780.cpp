#include <bits/stdc++.h>
using namespace std;

int n;
int board[2500][2500];
int pick, answer[3];
bool check(int N, int x, int y) {
    pick = board[x][y];
    for (int i = x; i < x+N; i++) {
        for (int j = y; j < y+N; j++) {
            if(pick != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}
void solve(int N, int x, int y) {
    if(check(N,x,y)) {
        answer[pick+1]++;
    } else {
        solve(N/3, x, y);//00
        solve(N/3, x, y+N/3);//01
        solve(N/3, x, y+2*N/3);//02
        solve(N/3, x+N/3, y);//10
        solve(N/3, x+N/3, y+N/3);//11
        solve(N/3, x+N/3, y+2*N/3);//12
        solve(N/3, x+2*N/3, y);//20
        solve(N/3, x+2*N/3, y+N/3);//21
        solve(N/3, x+2*N/3, y+2*N/3);//22
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }        
    }
    //search
    solve(n,0,0);
    cout << answer[0] << "\n";
    cout << answer[1] << "\n";
    cout << answer[2];
    return 0;
}