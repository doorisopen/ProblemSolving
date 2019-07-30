#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 정점의 개수, 간선의 개수, 시작할 정점  
int N,M,V;
// 방문처리를 위한 배열 
int c[1001];
int c2[1001];
// N개의 인접한 노드를 넣어주기위한 백터
vector<int> a[1001];

void dfs(int x){
	if(c2[x]) return; 
	c2[x] = true; 
	cout << x << ' ';
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];
		dfs(y);
	}
}
void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			// 방문한 상태가 아니라면 큐에 넣어준다.
			if(!c[y]){
				q.push(y);
				c[y] = true; 
			}
		}
	}
}

int main(void){
	int n1,n2;
	cin >> N >> M >> V;
	
	for(int i = 0; i < M; i++){
		cin >> n1 >> n2;
		a[n1].push_back(n2);
		a[n2].push_back(n1);
	}
	for(int i = 1; i <=N; i++)
		sort(a[i].begin(), a[i].end());
	
	dfs(V);
	cout<<endl;
	bfs(V);

	return 0;
}
