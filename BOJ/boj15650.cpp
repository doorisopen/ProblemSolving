// 15650 - N과 M(2) 조합(재귀) 
#include <stdio.h>
#include <vector>
#define MAX 9

using namespace std;
int N, M;
int arr[MAX];
bool select[MAX];
vector<int> v;

void print() {
	for(int i = 1; i <= N; i++) {
		if(select[i] == true) {
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}

void dfs(int idx, int cnt) {

	if(cnt == M) { // M개의 조합이 되었을때 출력한다 
		print();
		return;
	}
	for(int i = idx; i <= N; i++) {
		if(select[i] == true) continue;
		select[i] = true;
		dfs(i, cnt+1);
		select[i] = false;
	}
}
int main(void) {
	
	scanf("%d %d",&N ,&M);
	for(int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	
	dfs(1, 0);
	
	return 0;
} 