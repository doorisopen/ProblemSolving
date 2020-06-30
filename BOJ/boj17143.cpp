// BOJ 17143 낚시왕
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
struct info {
    int speed;
    int dir;
    int size;
};
const int dx[5] = { 0,-1,1,0,0 };
const int dy[5] = { 0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
int R, C, M, r, c, s, d, z;
int getShark = 0;
info pool[101][101];//d=> 1 위 2 아래 3 오른쪽 4 왼쪽
int check[101][101];

void printMap(int step) {
    cout << "\n==map==="<< step <<"=====\n";
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int a = pool[i][j].speed;
            int b = pool[i][j].dir;
            int c = pool[i][j].size;
            cout << a << b << c << " ";
        }
        cout << "\n";
    }
}
void printCheck(int step) {
    cout << "\n==check==="<< step <<"=====\n";
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cout << check[i][j] << " ";
        }
        cout << "\n";
    }
}

void fishing(int step) {
    vector<info> moved[101][101];

    //step의 row 제거
    for (int i = 1; i <= R; i++) {
        if(check[i][step] == 1) {
            getShark += pool[i][step].size;
            pool[i][step].speed = 0;
            pool[i][step].dir = 0;
            pool[i][step].size = 0;
            check[i][step] = 0;
            break;
        }
    }
    //상어 이동한다.
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if(check[i][j] == 1) {
                int moveCnt = pool[i][j].speed;
                int moveDir = pool[i][j].dir;
                int size = pool[i][j].size;
                int x = i, y = j;

                //이동 최적화
                if(moveDir == 1 || moveDir == 2) {
                    moveCnt = moveCnt % ((R - 1)*2);
                } else {
                    moveCnt = moveCnt % ((C - 1)*2);
                }
                //상어 이동
                for (int k = 0; k < moveCnt; k++) {
                    x += dx[moveDir];
                    y += dy[moveDir];
                    if(x > R || y > C || x < 1 || y < 1) {
                        if(moveDir == 1 || moveDir == 3) {
                            moveDir++;
                        } else {
                            moveDir--;
                        }
                        x += dx[moveDir];
                        y += dy[moveDir];
                        k--;
                    }
                }
                //이동 완료
                moved[x][y].push_back({moveCnt, moveDir, size});
                pool[i][j].speed = 0;
                pool[i][j].dir = 0;
                pool[i][j].size = 0;
                check[i][j] = 0;
            }
        }
    }

    //겹친 상어 비교
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if(moved[i][j].size() > 1) {
                int tmpIdx = 0;
                int tmpSize = moved[i][j][0].size;
                for (int k = 1; k < moved[i][j].size(); k++) {
                    if(tmpSize < moved[i][j][k].size) {
                        tmpIdx = k;
                        tmpSize = moved[i][j][k].size;
                    }
                }
                pool[i][j].speed = moved[i][j][tmpIdx].speed;
                pool[i][j].dir = moved[i][j][tmpIdx].dir;
                pool[i][j].size = moved[i][j][tmpIdx].size;
                check[i][j] = 1;
                continue;
            }
            if(moved[i][j].size() == 1) {
                pool[i][j].speed = moved[i][j][0].speed;
                pool[i][j].dir = moved[i][j][0].dir;
                pool[i][j].size = moved[i][j][0].size;
                check[i][j] = 1;
            }
        }        
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    //input
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        pool[r][c].speed = s;
        pool[r][c].dir = d;
        pool[r][c].size = z;
        check[r][c] = 1;
    }
    
    //search
    for (int step = 1; step <= C; step++) {
        fishing(step);
    }
    cout << getShark;
    
    return 0;
}