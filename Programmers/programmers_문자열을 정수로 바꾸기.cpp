// Level 1. 문자열을 정수로 바꾸기
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = atoi(s.c_str());
    return answer;
}