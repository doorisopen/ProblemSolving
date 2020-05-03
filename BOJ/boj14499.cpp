#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, x, y, k;
int dice[4][3] = {
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0}
                };
int moveX[5] = {0,0,0,-1,1};
int moveY[5] = {0,1,-1,0,0};
vector<vector<int> > mymap;
vector<int> command;

void diceMove(int d) {
    int tmp;
    switch (d) {
    case 1://동
        tmp = dice[3][1];//bottom
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = tmp;
        break;
    case 2://서
        tmp = dice[3][1];//bottom
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = tmp;
        break;
    case 3://북
        tmp = dice[3][1];//bottom
        dice[3][1] = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = tmp;
        break;
    case 4://남
        tmp = dice[3][1];//bottom
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
        break;
    default:
        break;
    }
}

void solve(int r, int c) {
    for (int i = 0; i < command.size(); i++) {
        int move = command[i];
        int nx = moveX[move];
        int ny = moveY[move];
        
        if(r+ny >= 0 && c+nx >= 0 && r+ny < m && c+nx < n) {
            c += nx;
            r += ny;
            diceMove(move);
            if(mymap[c][r] == 0) {
                mymap[c][r] = dice[3][1];
            } else {
                dice[3][1] = mymap[c][r];
                mymap[c][r] = 0;
            }
            cout << dice[1][1] << "\n";
        }
    }
    
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> y >> x >> k;

    mymap.assign(n, vector<int>(m, 0));
    command.assign(k,0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mymap[i][j];
        }   
    }

    for (int i = 0; i < k; i++)
    {
        cin >> command[i];
    }
    
    solve(x, y);

    return 0;
}