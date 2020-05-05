#include <bits/stdc++.h>
using namespace std;
int dice[4][3] = {
                {0,0,0},
                {0,0,0},
                {0,0,0},
                {0,0,0}
                };
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    diceMove(1);//동쪽으로 1번 굴리기
    diceMove(2);//서쪽으로 1번 굴리기
    diceMove(3);//북쪽으로 1번 굴리기
    diceMove(4);//남쪽으로 1번 굴리기

    return 0;
}