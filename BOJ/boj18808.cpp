#include <bits/stdc++.h>
using namespace std;

int board[41][41];
int sticky[12][12];
int n,m,k;
int r,c;

void rotate() {
    int temp[12][12];
    //copy
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = sticky[i][j];
        }        
    }
    //rotate
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticky[i][j] = temp[r-1-j][i];
        }
    }
    r^=c^=r^=c;
}

bool isAttachable(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(board[x+i][y+j] == 1 && sticky[i][j] == 1) {
                return false;
            }
        }        
    }
    //attach
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(sticky[i][j] == 1) {
                board[x+i][y+j] = 1;
            }
        }        
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticky[i][j];
            }
        }
        for (int rot = 0; rot < 4; rot++) {
            bool isAttached = false;
            for (int x = 0; x <= n-r; x++) {
                if(isAttached) break;
                for (int y = 0; y <= m-c; y++) {
                    if(isAttachable(x,y)) {
                        isAttached = true;
                        break;
                    }
                }
            }
            if(isAttached) break;
            rotate();
        }
    }
    //calc
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += board[i][j];
        }
    }
    cout << cnt << "\n";
    return 0;
}