#include <string>
#include <vector>
#include <queue>
using namespace std;
//0:먼저 방문할 곳, 2: 0번 방문 후 방문할 곳 1:아무것도아님
int check[200001];
int visit[200001];//방문
int afterVisit[200001];//나중방문
int priorityVisit[200001];//우선방문
vector<int> v[200001];//경로
queue<int> q;
void dfs(int num) {
    if(check[num] == 2) {
        afterVisit[num] = 1;
        return;
    }
    if(visit[num] == 1) return;
    visit[num] = 1;
    if(check[num] == 0) {
        q.push(priorityVisit[num]);
        check[num] = 1;
    }
    for(int next : v[num]) {
        if(visit[next] == 1) continue;
        dfs(next);
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    //경로 입력
    for(int i = 0; i < path.size(); i++) {
        v[path[i][0]].push_back(path[i][1]);
        v[path[i][1]].push_back(path[i][0]);
    }
    //방문지 설정
    for(int i = 0; i < n; i++) check[i] = 1;
    for(int i = 0; i < order.size(); i++) {
        check[order[i][0]] = 0;
        check[order[i][1]] = 2;
        priorityVisit[order[i][0]] = order[i][1];
    }
    //사전방문
    dfs(0);
    
    //나중방문
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        check[cur] = 1;
        if(afterVisit[cur] == 1) dfs(cur);
    }
    
    //방문확인
    for(int i = 0; i < n; i++) {
        if(visit[i] != 1) return false;
    }
    return answer;
}