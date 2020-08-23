#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int update[21][21];

void rotate() {
    int temp[21][21];
    //copy
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = update[i][j];
        }        
    }
    //rotate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            update[i][j] = temp[n-1-j][i];
        }
    }
}
void blockMove(int dir) {
    while (dir--) rotate();
    for (int i = 0; i < n; i++) {
        int check[21] = {};
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if(update[i][j] == 0) continue;
            if(check[idx] == 0) {
                check[idx] = update[i][j];
            } else if(check[idx] == update[i][j]) {
                check[idx++] *= 2;
            } else {
                check[++idx] = update[i][j];
            }
        }
        for (int j = 0; j < n; j++) {       
            update[i][j] = check[j];
        }
    }
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
    int mx = 0;
    for (int step = 0; step < 1<<10; step++) {//가능한 방향의 개수 4^5
        //copy
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                update[i][j] = board[i][j];
            }
        }
        //search
        int tmp = step;
        for (int i = 0; i < 5; i++) {
            int dir = tmp%4;
            tmp /= 4;
            blockMove(dir);
        }
        
        //calc
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, update[i][j]);
            }
        }
    }
    cout << mx;
    return 0;
}