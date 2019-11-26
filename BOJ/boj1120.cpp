// BOJ 1120 ¹®ÀÚ¿­ https://www.acmicpc.net/problem/1120
#include <iostream>
#include <algorithm>
using namespace std;

string wordA, wordB;
int tmp = 999999, cnt = 0;

int main(void) {
	
	int gap = 0;
	cin >> wordA >> wordB;
	for(int i = 0; i <= wordB.size() - wordA.size(); i++) {
		cnt = 0;
		for(int j = 0; j < wordA.size(); j++) {
			if(wordA[j]!=wordB[j+i]) cnt++;
		}
		tmp = min(cnt, tmp);
	}

	cout << tmp << endl;
	
	return 0;
} 
