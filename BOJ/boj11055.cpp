// 11055 가장 큰 증가 부분 수열
#include <iostream>
#include <algorithm>
#define ARRAYSIZE(A) sizeof(A)/sizeof((A)[0])
using namespace std;

int dp[1001];
int isBigger[1001];


int main(void) {
	
	int n,a,sum=0;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		dp[i] = a;
	}
	fill_n(isBigger, 1001, 0);
	for(int i = 1; i <= n; i++) {
		isBigger[i] = dp[i];
		for(int j = 1; j < i; j++) {
			if(dp[i] > dp[j] && isBigger[i] < isBigger[j] + dp[i]) {
				cout << isBigger[j] << "+" << dp[i] << "=";
				isBigger[i] = isBigger[j] + dp[i];
				cout << isBigger[i] << " ";
			}	
		}
		cout << endl;
	}
	for(int i = 1; i <= n; i++) {
		cout << isBigger[i] << " ";
	}
	cout << endl;
	sum = *max_element(isBigger, isBigger+ARRAYSIZE(isBigger)-1);
	cout << sum;
	return 0;
} 
