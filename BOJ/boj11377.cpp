// 11377 - ������ȣ 3
/* Ǯ�̹� *
Ư���� ������ ���ؼ��� 2���� ���� �� �� �ֵ��� ��Ī�ϴ� ����
��� ������ ���� 1���� ��Ī�� ���ְ�, ������ Ư���� ������ ���� ��ŭ�� �߰������� �� ���� �� ��Ī�� ���ָ�ȴ�. 
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
	// 2���� �۾��� �� �ִ� ����� �߰������� ����Ѵ�.
	int extra = 0;
	for(int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if(dfs(i)) extra++;
	} 
	printf("%d", count + extra);
	return 0;
}
