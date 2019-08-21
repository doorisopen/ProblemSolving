// 1149 - RGB°Å¸® 
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1001][3];
int N;
int r,g,b;

int main(void) {
	
	scanf("%d",&N);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d",&r ,&g ,&b);
		dp[i][0] = r;
		dp[i][1] = g;
		dp[i][2] = b;
	}
	
	for(int i = 0; i < N; i++) {
		dp[i+1][0] = dp[i+1][0] + min(dp[i][1], dp[i][2]);
		dp[i+1][1] = dp[i+1][1] + min(dp[i][0], dp[i][2]);
		dp[i+1][2] = dp[i+1][2] + min(dp[i][0], dp[i][1]);
	}
	
	int tmp = min(dp[N-1][1],dp[N-1][2]);
	printf("%d",min(dp[N-1][0],tmp));
	
	return 0;
}

