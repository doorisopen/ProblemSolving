#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, id;
int room[100005];
int d[100005];
int visit[100005];
vector<vector<int> > group;
stack<int> s;

void printAll() {
    cout << "group size=" << group.size() << "\n";
    for(int i = 0; i < group.size(); i++) {
    cout << "NO." << i + 1 << "= ";
        for(int j = 0; j < group[i].size(); j++) {
            cout << group[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "d is=====\n";
    for(int j = 1; j <= n; j++) {
        cout << d[j] << " ";
    }
    cout << "\n";
}

int dfs(int x) {
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    int next = room[x];

    if(d[next] == 0) parent = min(parent, dfs(next));
    else if(!visit[next]) parent = min(parent, d[next]);
    
    if(parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top(); s.pop();
            scc.push_back(t);
            visit[t] = true;
            if(t == x) break;
        }
        group.push_back(scc);
    }
    return parent;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> room[i];
        }
        
        for (int i = 1; i <= n; i++) {
            if(d[i] == 0) dfs(i);
        }
        
        printAll();

        int outsider = group.size(); 
        for(int i = 0; i < group.size(); i++) {
            if(group[i].size() == 1) {
                if(group[i][0] == room[group[i][0]]){
                    outsider--;
                } 
            } else {
                outsider--;
            }
        }
        cout << outsider << "\n";
        id = 0;
        while (!s.empty()){
            s.pop();
        }
        group.clear();
        memset(room, 0, sizeof(room));
        memset(d, 0, sizeof(d));
        memset(visit, 0, sizeof(visit));
    }
    return 0;
}