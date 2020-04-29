#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, w = 0, b = 0;
int m[12][12];
bool visit[12][12];
vector<pair<int, int> > v;

bool isPossible(int x, int y) {
    //왼쪽 대각선
    int nx = x - 1;
    int ny = y - 1;
    while(nx>=0 && ny>=0) {
        if(visit[nx--][ny--]) return false;
    }

    //오른쪽 대각선
    nx = x - 1;
    ny = y + 1;
    while(nx>=0 && ny<n) {
        if(visit[nx--][ny++]) return false;
    }

    return true;
}

void dfs(int idx, int cnt, bool isW) {
    if(isW) {
        w = max(w, cnt);
    } else {
        b = max(b, cnt);
    }

    for (int i = idx; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if(isW) {//white
            if(x%2 == 0 && y%2 != 1) continue;
            else if(x%2 == 1 && y%2 != 0) continue;
        } else {//black
            if(x%2 == 0 && y%2 != 0) continue;
            else if(x%2 == 1 && y%2 != 1) continue;
        }

        if(!visit[x][y] && isPossible(x,y)) {
            visit[x][y] = true;
            if(isW) {
                dfs(i+1, cnt+1, true);
            } else {
                dfs(i+1, cnt+1, false);
            }
            visit[x][y] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    //Map저장
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m[i][j];
            if(m[i][j] == 1) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0, 0, true);//white
    dfs(0, 0, false);//black

    cout << w + b << "\n";

    return 0;
}