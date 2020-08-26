/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 괄호 변환
 */
#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string s) {
  int check = 0;
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '(') {
      check++;
    } else {
      check--;
    }
    if(check < 0) return false;
  }
  return check==0;
}
string search(string s) {
  //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
  if(s.length() == 0) return s;

  //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
  //단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며,
  //v는 빈 문자열이 될 수 있습니다.
  int i, check = 0;
  for (i = 0; i < s.length(); i++) {
    if(s[i] == '(') {
      check++;
    } else {
      check--;
    }
    if(check == 0) break;
  }
  string u = s.substr(0, i+1);
  string v = s.substr(i+1);
  //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
  if(isCorrect(u)) {
    //3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
    return u + search(v);
  } else {
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    //4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
    //4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
    //4-3. ')'를 다시 붙입니다.
    string w = "(" + search(v) + ")";
    //4-4. u의 첫 번째와 마지막 문자를 제거하고,
    //나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
    for (int i = 1; i < u.length()-1; i++) {
      if(u[i] == '(') {
        w += ')';
      } else {
        w += '(';
      }
    }
    //4-5. 생성된 문자열을 반환합니다.
    return w;
  }
}

string solution(string p) {
  return search(p);;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << solution("()))((()");
  return 0;
}