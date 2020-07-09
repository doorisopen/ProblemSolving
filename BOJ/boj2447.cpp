#include <iostream>

using namespace std;
int n;
char board[10000][10000];
void solve(int N, int x, int y) {

    if(N == 1) {
        board[x][y] = '*';
        return;
    }

    solve(N/3, x, y);//00
    solve(N/3, x+N/3, y);//10
    solve(N/3, x+2*N/3, y);//20
    solve(N/3, x, y+N/3);//01
    solve(N/3, x+2*N/3, y+N/3);//21
    solve(N/3, x, y+2*N/3);//02
    solve(N/3, x+N/3, y+2*N/3);//12
    solve(N/3, x+2*N/3, y+2*N/3);//22
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }
    
    solve(n,0,0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}