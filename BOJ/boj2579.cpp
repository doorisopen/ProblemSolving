// [BOJ] 2579 - 계단 오르기 
#include <iostream>
#include <algorithm>
using namespace std;


int dp[301], array[301];
int N, sum;

int f() {
	for(int i = 0; i < N; i++) { 
		dp[i] = max(array[i] + dp[i-2] , array[i] + dp[i-3] + array[i-1]); 
	}
	return dp[N-1];
}

int main(void) {
	int stair;
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> stair; 
		array[i] = stair;
	}
	cout << f() << " ";
	return 0;
}

