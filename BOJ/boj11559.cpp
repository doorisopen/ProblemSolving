#include <bits/stdc++.h>
using namespace std;
#define ll long long

char m[13][7]; //map
bool check[13][7]; //방문확인
int dc[4] = {1,-1,0,0}; //x 동서남북
int dr[4] = {0,0,1,-1}; //y
int block_cnt = 0; //블럭갯수
bool isDestory;
int destoryCnt = 0;
vector<pair<int, int> > destroyBlock, destroiedBlock;

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++)
    {
        int nc = c + dc[i]; //다음 열
        int nr = r + dr[i]; //다음 행

        if(nc < 0 || nr < 0 || nc >= 6 || nr >= 12) continue;
        if(m[nr][nc] == '.') continue;
        if(check[nr][nc]) continue;
        if(m[nr][nc] != m[r][c]) continue;

        block_cnt++;
        check[nr][nc] = true;
        destroyBlock.push_back(make_pair(nr, nc));
        dfs(nr, nc);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //input
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> m[i][j];
        }
    }
    //search
    while (1) {
        isDestory = false;
        memset(check, false, sizeof(check));
        destroiedBlock.clear();

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if(m[i][j] != '.' && !check[i][j]) {
                    block_cnt = 1;
                    destroyBlock.push_back(make_pair(i,j));
                    check[i][j] = true;
                    dfs(i, j);

                    //블럭 4개 이상이면
                    if(block_cnt >= 4) {
                        isDestory = true;
                        for (int i = 0; i < destroyBlock.size(); i++) {
                            destroiedBlock.push_back(destroyBlock[i]);
                        }
                    }
                    destroyBlock.clear();
                }
            }
        }

        //블럭파괴
        for (int i = 0; i < destroiedBlock.size(); i++) {
            m[destroiedBlock[i].first][destroiedBlock[i].second] = '.';
        }

        //map변경
        for (int i = 10; i >= 0; i--) {
            for (int j = 0; j < 6 ; j++) {
                if(m[i][j] == '.') continue;
                int tmp = i;

                while (1) {
                    if(tmp == 11 || m[tmp + 1][j] != '.') break;
                    m[tmp + 1][j] = m[tmp][j];
                    m[tmp][j] = '.';
                    tmp++;
                }
            }
        }
        if(isDestory) {
            destoryCnt++;
        } else {
            break;
        }
    }
    cout << destoryCnt;
    return 0;
}