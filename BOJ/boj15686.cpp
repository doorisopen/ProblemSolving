#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;

int n,m,minnum=9999,picknum = 0; // 선택된 가게들의 최소값의 합
int board[100][100];
int check[100][100];
int mCheck[13];
queue<pi> q;
vector<pi> homeP;//집 모든 위치
vector<pi> chickP;//치킨집 모든 위치
vector<pi> chickPick;//선택된 치킨집 

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            check[i][j] = 0;
        }        
    }
}

void search() {
    for (int i = 0; i < chickPick.size(); i++) {
        int chickX = chickPick[i].first;
        int chickY = chickPick[i].second;
        check[chickX][chickY] = -1;
        
        for (int j = 0; j < homeP.size(); j++) {
            int homeX = homeP[j].first;
            int homeY = homeP[j].second;
            if(board[homeX][homeY]) {
                if(check[homeX][homeY]==0) check[homeX][homeY] = abs(chickX-homeX) + abs(chickY-homeY);
                if(check[homeX][homeY] > abs(chickX-homeX) + abs(chickY-homeY)) {
                    check[homeX][homeY] = abs(chickX-homeX) + abs(chickY-homeY);
                }
            }
            
        }
    }
    //calc
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(check[i][j] > 0) {
                picknum += check[i][j];
            }
        }        
    }
    // cout << picknum << "<=\n";
    minnum = min(minnum, picknum);
    picknum = 0;
    init();
}

void pick(int d, int idx, int limit) {
    if(d==limit) {
        search();
        return;
    }
    for (int i = idx; i < chickP.size(); i++) {
        if(!mCheck[i]) {
            mCheck[i] = 1;
            chickPick.push_back({chickP[i].first,chickP[i].second});
            pick(d+1,i,limit);
            chickPick.pop_back();
            mCheck[i] = 0;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    //input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                chickP.push_back({i,j});
            }
            if(board[i][j] == 1) {
                homeP.push_back({i,j});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        pick(0,0,i);
    }
    
    cout << minnum;
    return 0;
}