/* 
 * 월간 코드 첼린지 시즌1
 * 3진법 뒤집기
 */
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;

	string bitstr = "";
	int N = n;
	while(N) {
		bitstr += to_string(N%3);
		N /= 3;
	}

	int calc = 0, idx = 0;
	for (int j = bitstr.length()-1; j >= 0; j--) {
		calc += (bitstr[j]-'0') * pow(3,idx++);
	}
	answer = max(answer, calc);
	cout << answer;
    return answer;
}

int main(void){
	solution(45);
	return 0;
}