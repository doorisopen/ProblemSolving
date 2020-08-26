/**
 * 2020 KAKAO BLIND RECRUITMENT
 * 문자열 압축
 */
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    string compression = "";

    for (int cut = 1; cut <= len/2; cut++) {
      //cut 길이 만큼 부분 문자열로 자른다.
      vector<string> cutting;
      for (int i = 0; i < len; i+=cut) {
        cutting.push_back(s.substr(i,cut));
      }

      compression = "";//압축 결과
      string cur = cutting[0];//시작점
      int cnt = 1;
      for (int i = 1; i < cutting.size(); i++) {//압축
        if(cur == cutting[i]) {
          cnt++;
        } else {
          if(cnt!=1) {
            compression += to_string(cnt);
          }
          compression += cur;
          cur = cutting[i];
          cnt = 1;
        }
      }
      //압축 후 압축안됐을때
      if(cnt!=1) compression += to_string(cnt);
      compression += cur;
      //길이 비교
      answer = min(answer, (int)compression.length());
    }
    cout << answer;
    return answer;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solution("aabbaccc");
    return 0;
}