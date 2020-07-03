
### cpp

```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    int len = 0;
    int idx;
    for(int a = 0; a < k; a++){
        len = number.size();
        idx = len - 1;
        for(int b = 0; b < len-1; b++){
            if (number[b] < number[b + 1]) {
                idx = b;
                break;
            }
        }
        number.erase(number.begin()+idx);
    }
    return number;
}
```

### java
* String, StringBuffer, StringBuilder 차이 중요!

String의 경우 immutable(불변)하고 StringBuffer와 StringBuilder는 mutable(가변)하다. 

String 클래스는 StringBuffer 클래스나 StringBuilder 클래스와 다르게 리터럴을 통해 생성되면 그 인스턴스의 메모리 공간은 절대 변하지 않는다.

StringBuffer는 동기화를 지원해서 thread-safe함 __StringBuilder는 동기화를 지원하지 않아서 StringBuffer보다 연산처리가 빠르다.__

```
import java.util.Arrays;

class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        int i=0;
        int j=0;
        int len;
        int idx;
        for(i = 0; i < k; i++) {
            len = sb.length();
            idx = len - 1;
            for(j = 0; j < len-1; j++) {
                if(sb.charAt(j) < sb.charAt(j+1)) {
                    idx = j;
                    break;
                }
            }
            sb.deleteCharAt(idx);
        }
        return sb.toString();
    }
}
```