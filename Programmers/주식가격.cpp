/* 
 * 스택/큐
 * 주식가격
 * 주식의 값이 떨어지기 까지의 시간
 * [1,2,3,2,1]
 * 1->[2,3,2,1] : 4초
 * 2->[2,3,2,down] : 3초
 * 3->[down] : 1초
 * 2->[down] : 1초
 * 1->none : 0초
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
	int n = prices.size();
    vector<int> answer(n);
	stack<int> stk;
	for (int i = 0; i < n; i++) {
		while(!stk.empty()&&prices[stk.top()] > prices[i]) {
			int tp = stk.top(); stk.pop();
			answer[tp] = i-tp;
		}
		stk.push(i);
	}
	
	
	while (!stk.empty()) {
		int tp = stk.top(); stk.pop();
		answer[tp] = n - 1 - tp;
	}
    return answer;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
	solution({1,2,3,2,1});
	return 0;
}