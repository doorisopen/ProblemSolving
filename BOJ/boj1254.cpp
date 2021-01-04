/* 
 * 1254 팰린드롬 만들기
 */
#include <bits/stdc++.h>
using namespace std;

int solution() {
    string plain;
    cin >> plain;

    int answer = 0;
    int len = plain.size();
    for (int idx = 0; idx < len; idx++) {
        bool isPass = true;
        for (int i = 0; idx+i < len-1-i; i++) {
            if (plain[idx+i] != plain[len-1-i]) {
                isPass = false;
                break;
            }
        }
        if (isPass) {
            answer = len + idx;
            break;
        }
    }
    return answer;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << solution();
	return 0;
}