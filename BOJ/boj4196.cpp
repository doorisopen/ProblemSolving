// 4196 - 도미노
/* 풀이법 *
이 문제는 단순히 강한 결합 요소만을 구하는 문제가 아니라 강한 결합 요소 사이의 관계 까지도 구해야하는 문제이다.
강한 결합 요소끼리는 일방향적으로 연결되어 있다는 점에서 위상 정렬을 수행할 수 있다.
도미노는 강한 결합 요소를 정점으로 보고 위상정렬을 수행 했을 때 진입 차수가 0인 정점의 갯수를 세면 되는 문제이다. 

모든 강한 결합 요소에 대해서 각각 고유한 번호 값을 매겨 그룹을 만든 뒤에, 각각의 그룹을 하나의 정점으로 보고 단순하게 진입 차수의 갯수만
세어주면 된다. 이후에 각 그룹에 대해 진입 차수의 갯수가 0인 경우에만 카운트를 해주어서 결과적으로 최종 카운트를 출력하면된다. 
*/ 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001
using namespace std; 

int n, m; 
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];

// 항상 처음 방문하는 노드만 실행된다. 즉, N번 수행
int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	
	int result = d[x];
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// 아직 방문하지 않은 이웃 노드인 경우
		if(d[y] == 0) result = min(result, dfs(y));
		// 방문은 했지만 아직 처리 중인 이웃 노드인 경우
		else if(!finished[y]) result = min(result, d[y]); 
	}
	
	// 부모 노드가 자기 자신인 경우 SCC를 형성합니다.
	if(result == d[x]) {
		vector<int> scc;
		while(1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1; // 강한결합요소의 id 값이라고 생각하면된다. 
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	} 
	
	// 자기의 부모 값을 반환 합니다.
	return result;
} 
int main(void) {
	int t;
	scanf("%d", &t); 
	
	while(t--) {
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		scanf("%d %d", &n ,&m);
		for(int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d",&x ,&y);
			a[x].push_back(y);
		}
		for(int i = 1; i <= n; i++) {
			if(d[i] == 0) dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < a[i].size(); j++) {
				int y = a[i][j];
				if(group[i] != group[y])
					inDegree[group[y]] = true;
			}
		}
		int result = 0;
		for(int i = 1; i <= SCC.size(); i++) {
			if(!inDegree[i]) result++;
		}
		printf("%d\n", result);	
	}
	return 0;
}



