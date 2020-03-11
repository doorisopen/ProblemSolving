
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42576)

## c++

```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    
    for(int i = 0; i < participant.size(); i++) {
        if(participant[i] != completion[i]) {
            return participant[i];
        }
    }
    return participant[participant.size()];
}
```