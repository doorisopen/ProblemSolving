// 1671 - 상어의 저녁식사 
/* 풀이법 *
 2번씩 매칭을 수행해주면 되는 이분 매칭 문제
 다만 문제에서는 상어들의 능력 수치에 따라서 매칭을 시켜주라고 지시하고 있으므로 능력 수치를 비교하는 부분만 신경써주면된다. 
*/ 
#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int stat[MAX][3];
int d[MAX];
bool c[MAX];
int n, m, s, k;

bool dfs(int x) {
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(c[y]) continue;
		c[y] = true;
		// 현재 잡아먹으려는 상어에게 점유를 안당했거나
		// 현재 점유하고 있는 상어를 잡아먹으려는 상어가 점유할 수 있다면 점유하게 한다. 
		if(d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		int a, b, c; 
		scanf("%d %d %d" ,&stat[i][0] ,&stat[i][1] ,&stat[i][2]);
	}
		
	for(int i = 1; i <= n - 1; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) {
				a[i].push_back(j);
			} else if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
				a[i].push_back(j);
			} else if(stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]) {
				a[j].push_back(i);
			}
		}
	}
	int count = 0;
	for(int k = 0; k < 2; k++) {
		for(int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if(dfs(i)) count ++;
		}
	}
	printf("%d", n - count);
	return 0;
}
