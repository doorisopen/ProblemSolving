/** 2606 바이러스
 */
#include <bits/stdc++.h>
#define MAX 2000001
using namespace std;
vector<int> v[101];
int visit[101];
int n,cPair,virus=-1;

void dfs(int n) {
    if(visit[n]) return;
    visit[n] = 1;
    virus++;

    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if(!visit[next]) dfs(next);
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> cPair;
    for (int i = 0; i < cPair; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    dfs(1);
    cout << virus;
    return 0;
}