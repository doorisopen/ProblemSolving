

[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42588)

## c++

```
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    stack<int> s;
    
    for(int i = 0; i < heights.size(); i++) {
        s.push(heights[i]);
    }
    
    int t_idx = heights.size()-1;
    while(!s.empty()) {
        int t = s.top();
        s.pop();
    
        for(int i = t_idx-1; i >= 0; i--) {
            if(heights[i] > t) {
                // cout << heights[i] << ">" << t << endl;
                answer[t_idx] = i+1;
                break;
            }
        }
        t_idx--;
    }
    
    return answer;
}
```