/** 2580 스도쿠
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int board[9][9];
vector<pi> blank;

void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isPossible(int x, int y, int val) {
    //세로
    for (int i = 0; i < 9; i++) {
        if(board[i][y] == val) {
            return false;
        }
    }
    //가로
    for (int i = 0; i < 9; i++) {
        if(board[x][i] == val) {
            return false;
        }
    }
    //네모
    int c = x - x%3;
    int r = y - y%3;
    for (int i = c; i < c+3; i++) {
        for (int j = r; j < r+3; j++) {
            if(board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}
void dfs(int d) {
    if(d == blank.size()) {
        printBoard();
        exit(0);
    }

    for (int i = 1; i <= 9; i++) {
        int nx = blank[d].first;
        int ny = blank[d].second;

        if(isPossible(nx,ny,i)) { //해당 위치, 해당 원소가 가능한지여부
            board[nx][ny] = i;
            dfs(d+1);
            board[nx][ny] = 0;
        }        
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                blank.push_back({i,j});
            }
        }
    }
    //search
    dfs(0);
    return 0;
}