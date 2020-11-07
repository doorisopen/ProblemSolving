/* 
 * 탐욕법
 * 조이스틱
 */
#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();

    for (int i = 0; i < len; i++) {
        if(name[i] != 'A') {
            int up = name[i]-'A';
            int down = 1+'Z'-name[i];
            answer += (up<down) ? up : down;
        }
    }
    int mnMove = len;
    for (int i = 0; i < len; i++) {
        if(name[i] != 'A') {
            int nxt = i+1;
            while (nxt < len && name[nxt] == 'A') {
                nxt++;
            }
            int move = 2*i+len-nxt;
            mnMove = min(mnMove, move);
        }
    }
    return answer+mnMove;
}

int main(void){
	cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution("JEROEN");
	return 0;
}