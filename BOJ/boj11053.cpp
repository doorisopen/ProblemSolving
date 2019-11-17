// 11053 가장 긴 증가하는 부분 수열
#include <iostream>
#include <algorithm>
#define ARRAYSIZE(A) sizeof(A)/sizeof((A)[0])
using namespace std;

int dp[1001];
int isUpper[1001];


int main(void) {
	
	int n,a,len=0;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		dp[i] = a;
	}
	fill_n(isUpper, 1001, 1);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(dp[i] > dp[j]) {
				if(isUpper[i] == isUpper[j]) {
					isUpper[i] += 1;
				} else if(isUpper[i] < isUpper[j]) {
					isUpper[i] = isUpper[j] + 1;
				}
			}	
		}
	}
	len = *max_element(isUpper, isUpper+ARRAYSIZE(isUpper)-1);
	cout << len;
	return 0;
} 
 
