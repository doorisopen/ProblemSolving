// 15649 - N과 M(1)
#include <stdio.h>
#include <vector>
#define MAX 9

using namespace std;
int N, M;
bool select[MAX];
vector<int> v;

void print() {
	for(int i = 0; i < v.size(); i++) {
		printf("%d ",v[i]);
	}
	printf("\n");
}

void dfs(int cnt) {

	if(cnt == M) { // M개의 조합이 되었을때 출력한다 
		print();
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(select[i] == true) continue;
		select[i] = true;
		v.push_back(i);
		dfs(cnt+1);
		select[i] = false;
		v.pop_back();
	}
}
int main(void) {
	
	scanf("%d %d",&N ,&M);
	dfs(0);
	
	return 0;
} 