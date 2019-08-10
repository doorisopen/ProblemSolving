// 11377 - 열혈강호 3
/* 풀이법 *
특정한 직원에 한해서만 2번씩 일을 할 수 있도록 매칭하는 문제
모든 직원에 대해 1번씩 매칭을 해주고, 나머지 특정한 직원의 숫자 만큼만 추가적으로 한 번씩 더 매칭을 해주면된다. 
*/ 
#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s, k;

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
	
	scanf("%d %d %d",&n ,&m ,&k);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&s);
		for(int j = 0; j < s; j++) {
			int t;
			scanf("%d",&t);
			a[i].push_back(t);
		}
	}
	int count = 0;
		
	for(int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	// 2번씩 작업할 수 있는 사람을 추가적으로 계산한다.
	int extra = 0;
	for(int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if(dfs(i)) extra++;
	} 
	printf("%d", count + extra);
	return 0;
}
