/* 
 * 11931 수 정렬하기 4
 */
#include <bits/stdc++.h>
using namespace std;

void solution() {
    int t, n;
	cin >> t;
	vector<int> arr;
	for(int i = 0; i < t; i++) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end(), greater<>());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}

int main(void){
	solution();
	return 0;
}