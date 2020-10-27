/* 
 * 1662 압축
 */
#include <bits/stdc++.h>
using namespace std;

string str;
int check[51];
stack<int> s;
int answer = 0;
int recursion(int s, int e) {
	int val = 0;
	for (int i = s; i < e; i++) {
		if(str[i] == '(') {
			int mul = str[i-1]-'0';
			val += mul * recursion(i+1,check[i])-1;
			i = check[i];
			continue;
		}
		val++;
	}
	return val;
}

void solution() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] == '(') {
			s.push(i);
		}
		if(str[i] == ')') {
			check[s.top()] = i;
			s.pop();
		}
	}
	cout << recursion(0,str.length());
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution();
	return 0;
}