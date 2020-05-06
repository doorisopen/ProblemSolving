#include <bits/stdc++.h>
using namespace std;
#define ll long long

int volt[5][9];
int command, no, dir, sum = 0;
void printAll() {
    cout << "====printAll====\n";
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 8; j++){
            cout << volt[i][j];
        }
        cout << "\n";
    }
}
void calc(){
    if(volt[1][1] == 1) {
        sum += 1;
    }
    if(volt[2][1] == 1) {
        sum += 2;
    }
    if(volt[3][1] == 1) {
        sum += 4;
    }
    if(volt[4][1] == 1) {
        sum += 8;
    }
}
void rotate(int idx, int direction) {
    if(direction == -1) {
        int start = volt[idx][1];
        for (int i = 2; i <= 8; i++){
            volt[idx][i-1] = volt[idx][i];
        }
        volt[idx][8] = start;
    } else {
        int end = volt[idx][8];
        for (int i = 8; i >= 2; i--){
            volt[idx][i] = volt[idx][i-1];
        }
        volt[idx][1] = end;
    }
    return;
}
void right(int n, int d) {
    if(!(1 <= n && n <= 4)) return;

    if(volt[n-1][3] != volt[n][7]) {
        right(n+1, -d);
        rotate(n, d);
    } else {
        return;
    }
}
void left(int n, int d) {
    if(!(1 <= n && n <= 4)) return;

    if(volt[n][3] != volt[n+1][7]) {
        left(n-1, -d);
        rotate(n, d);
    } else {
        return;
    }
}

int main() {
    int n;
    int arr[3][3] = {0,};
    
    int num;
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 8; j++){
            scanf("%1d",&volt[i][j]);
        }
    }

    cin >> command;
    for (int i = 0; i < command; i++){
        cin >> no >> dir;
        right(no+1, -dir);//right search
        left(no-1, -dir);//left search
        rotate(no, dir);
        // printAll();
    }
    // cout << volt[1][1] << " " << volt[2][1] << " " << volt[3][1] << " " << volt[4][1] << "\n";
    calc();
    cout << sum;

    return 0;
}