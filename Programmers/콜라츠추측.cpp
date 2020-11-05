/*
 * 연습문제
 */
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long int val = num;
    while(val != 1) {
        val = val%2 == 0 ? val/2 : val*3+1;
        answer++;
        if(answer == 500) {
            answer = -1;
            break;
        }
    }
    return answer;
}