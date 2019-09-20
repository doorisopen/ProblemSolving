// Level 1. 행렬의 덧셈 

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2) {
	
	vector<vector<int> > answer;
	
	for(int i = 0; i < arr1.size(); i++) {
		vector<int> v;
		for(int j = 0; j < arr1[0].size(); j++) {
			v.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(v);
	}
	
	
	return answer;
}

int main(void) {
	
	
	vector<vector<int> > arr1 = { { 1, 2 }, { 3, 4 } };
	vector<vector<int> > arr2 = { { 1, 2 }, { 3, 4 } };
	vector<vector<int> > show = solution(arr1, arr2);
	
	for(int i = 0; i < arr1.size(); i++) 
	{
		for(int j = 0; j < arr1[0].size(); j++) 
		{
			printf("%d ", show[i][j]);
		}
	}


	return 0;
}