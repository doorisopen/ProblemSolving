// 회의실 배정 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;

int main(void){
	int s, e;
	int Mnum, cur = 0, max = 0;

	cin >> Mnum;
	for(int i = 0; i < Mnum; i++){
		cin >> s >> e;
		v.push_back({e, s});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < Mnum; i++){
		if(v[i].second >= cur){
			cur = v[i].first;
			max++;
		}
	}
	cout << max;
	
	return 0;
}
