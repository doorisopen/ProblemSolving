
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42577)

## c++

```
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    
    for(int i = 0; i < phone_book.size(); i++) {
        string prefix = phone_book[i];
        for(int j = 0; j < phone_book.size(); j++) {
            if(i != j && phone_book[j].find(prefix) == 0 && phone_book[j].find(prefix) != string::npos) return false;
        }
    }   
    
    return true;
}
```