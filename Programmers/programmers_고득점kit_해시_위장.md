
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42578#qna)

옷의 종류가 A, B, C 라고 할때

__answer = (A+1)(B+1)(C+1)-1__ 이다.

## c++

```
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i = 0; i < clothes.size(); i++) {
        if(m.find(clothes[i][1]) == m.end()) {
            m.insert(make_pair(clothes[i][1], 1));
        } else {
            m[clothes[i][1]] += 1;
        }
    }
    map<string, int>::iterator iter;
    
    for(iter = m.begin(); iter != m.end(); iter++) {
        answer *= (iter->second + 1);
    }
    answer -= 1;
    
    return answer;
}
```