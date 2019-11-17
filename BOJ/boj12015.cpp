// 12015 ���� �� �����ϴ� �κ� ����2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

int main(void) {
	
	int n,a;
	
	cin>>n;
	dp.push_back(-1);
	
	while(n--) {
		cin >> a;
		
		if(dp.back() < a) {
			dp.push_back(a);
		} else {
			*lower_bound(dp.begin(),dp.end(),a) = a;
		}
	}
	cout << dp.size()-1;
	return 0;
} 
 
