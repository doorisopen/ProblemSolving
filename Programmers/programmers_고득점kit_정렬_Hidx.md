
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42747)

## c++

```
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    // 출력 for loop
    // for(int i = 0; i < citations.size(); i++) {
    //     cout << citations[i] << " ";    
    // }
    
    for(int i = 0; i <= citations.size(); i++) {
        int h = 0;
        
        for(int j = 0; j < citations.size(); j++) {
            if(i <= citations[j]) {
               h++;    
            }
        }
        cout << i << "-> "<< citations[i] << "= " << h << endl;
        if(i <= h) {
            answer = i;
        }
        cout << "a= " << answer <<endl;
    }
    
    return answer;
}
```