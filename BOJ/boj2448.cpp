#include <iostream>
using namespace std;

char board[4000][8000];
void solve(int N, int x, int y) {
    if(N==3) {
        /*
        ##* ->(0,2)
        #*#* ->(1,1),(1,3)
        ***** ->(2,0)x5
        */
        board[x][y+2] = '*';
        board[x+1][y+1] = '*';
        board[x+1][y+3] = '*';
        for (int i = 0; i < 5; i++) {
            board[x+2][y+i] = '*';
        }
        return;
    }
    solve(N/2, x, y+N/2);
    solve(N/2, x+N/2, y);
    solve(N/2, x+N/2, y+N);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    solve(n,0,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2-1; j++) {
            if(board[i][j]!='\0') { 
                cout << board[i][j]; 
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}