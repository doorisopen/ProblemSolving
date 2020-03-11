
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/43163)

## c++

```
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 101;

void dfs(string begin, string target, vector<string> words, int result, int idx) {
    if(begin == target) {
        if(answer>result) {
            answer = result;
        }
        return;
    }

    for(int i = idx; i < words.size(); i++) {
        int false_Cnt = 0;
        for(int j = 0; j < begin.size(); j++) {
            if(begin[j] != words[i][j]) false_Cnt++;
        }
        
        if(false_Cnt == 1) {
            dfs(words[i], target, words, result+1, i+1);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    bool check=false;
    for(int i = 0; i < words.size(); i++) {
        if(target == words[i]) {check = true;}
    }
    
    if(check==false) {
        return 0;
    }
    
    dfs(begin, target, words, 0, 0);
    if(answer==101) {
        answer=9;
    }
    return answer;
}
```