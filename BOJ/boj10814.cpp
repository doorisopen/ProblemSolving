/* 
 * 10814 나이순 정렬
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<pair<pi,string> > arr;
bool compare(pair<pi,string> a, pair<pi,string> b) {
	if(a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	} else {
		return a.first.first < b.first.first;
	}
}
void solution() {
    int t;
	cin >> t;

	int age;
	string name;
	for (int i = 0; i < t; i++) {
		cin >> age >> name;
		arr.push_back({{age,i},name});
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < t; i++) {
		cout << arr[i].first.first << " " << arr[i].second << "\n";
	}
}

int main(void){
	solution();
	return 0;
}