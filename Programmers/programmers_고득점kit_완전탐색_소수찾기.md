
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42839)

## c++

```
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
vector<int> isPrime;

int isPrimeNumbers(int num) {
    if(num == 0 || num == 1) return 0;
    if(isPrime.size() > 0) {
        for(int i = 0; i < isPrime.size(); i++) {
            if(num == isPrime[i]) return 0;
        }
    }
    
    int n = (int) sqrt(num);
    for(int i = 2; i <= n; i++) {
        if(num % i == 0)  {
            return 0;
        } else {
            isPrime.push_back(num);
        }
    }
    return 1;
}
int solution(string numbers) {
    int answer = 0;
    
    
    for(int i = 0; i < numbers.size(); i++) {
        string tmp = numbers[i];
        int num = atoi(tmp);
        if(isPrimeNumbers(num)) {
            answer++;
        }
        for(int j = 0; j < numbers.size(); j++) {
            tmp += numbers[j];
            num = stoi(numbers[i]);
            if(isPrimeNumbers(num)) {
                answer++;
            }
            tmp = numbers[i];
        }
    }
    
    return answer;
}
```