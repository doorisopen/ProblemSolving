/*#include <cstdio>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;
const int MAX=1000001;
int dp[MAX];

int f(int n) {
	int result;
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	result = f(n - 1) + 1;
	if (n % 3 == 0) { result = min(result, f(n / 3) + 1); }
	if (n % 2 == 0) { result = min(result, f(n / 2) + 1); }
	dp[n] = result;
	return result;
}

int main() {
	int n;
	scanf("%d", &n);
	fill(dp, dp+MAX, -1);
	printf("%d\n", f(n));
	return 0;
}*/