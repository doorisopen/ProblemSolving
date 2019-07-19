// ทฮวม 
#include <stdio.h>
#include <algorithm>
using namespace std;
int r[100001];

int main(void){
	int n;
	int tmp = 0, maxnum = -1;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		scanf("%d",&r[i]);
	}
	sort(r, r+n);
	for(int i = 0; i < n; i++){
		maxnum = max(maxnum, r[i]*(n - i));
	}
	printf("%d", maxnum);
	
	return 0;
}
