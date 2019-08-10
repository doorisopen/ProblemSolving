// 11376 - 열혈강호 2
/* 풀이법 *
각각의 직원이 최대 두 개의 일을 할 수 있다는 점에서 두 번씩 DFS를 수행해주면 된다.
어떠한 직원을 먼저 매칭시켜주든지 최종적으로 매칭되는 숫자가 동일하기 때문이다. 

*/ 
#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s;

bool dfs(int x) {
	
	for(int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		if(c[t] == true) continue;
		c[t] = true;
		if(d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	
	return false;
}

int main(void) {
	
	scanf("%d %d",&n ,&m);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&s);
		for(int j = 0; j < s; j++) {
			int t;
			scanf("%d",&t);
			a[i].push_back(t);
		}
	}
	int count = 0;
		
	for(int j = 0; j < 2; j++) {
		for(int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if(dfs(i)) count++;
		}
	}
	printf("%d", count);
	return 0;
}
