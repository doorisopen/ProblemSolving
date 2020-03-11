
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42840)

## c++

```
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int p[4][11] = {{0},
                {1,2,3,4,5},
                {2,1,2,3,2,4,2,5},
                {3,3,1,1,2,2,4,4,5,5}
               };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();
    int correct[4] = {0,0,0,0};
    
    for(int i = 1; i <= 3; i++) {
        int idx = 0;
        int idx2 = 0;
       while(idx < size) {
         if(p[i][idx2] == 0) {
             idx2 = 0;
         }
         if(answers[idx] == p[i][idx2]) {
             // cout << i << ": " << answers[idx] << "==" << p[i][idx2] << endl;
             correct[i] += 1;
             // cout << "corr: " << correct[i] << endl;
         }
           idx++;
           idx2++;
        }
    }
    int excellent = *max_element(correct,correct+4);
    for(int i = 1; i <= 3; i++) {
        if(excellent == correct[i]) {
            answer.push_back(i);
        }
    }
    
    return answer;
}
```