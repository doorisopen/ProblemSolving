#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 16

int n, result = 0;
int m[MAX];

bool isPossible(int c) {
    for (int i = 1; i < c; i++)
    {
        //같은 행에 있는지 여부
        if(m[i] == m[c]) {
            return false;
        }
        //대각선 검사
        if(abs(m[i] - m[c]) == abs(i - c)) {
            return false;
        }
    }
    return true;
}

void dfs(int d) {
    if(d > n) {
        ++result;
        return;
    } else {
        //d열 i행 탐색
        for (int i = 1; i <= n; i++)
        {
            m[d] = i;
            // 노드 확인
            if(isPossible(d)) {
                dfs(d+1);
            } else {
                //백트래킹
                m[d] = 0;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fill(m, m+n, 0);
        m[1] = i;
        dfs(2);
    }
    cout << result;
    return 0;
}