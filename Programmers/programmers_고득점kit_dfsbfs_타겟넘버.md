
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/43165)

## c++

```
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int total;

void DFS(vector<int> &numbers, int &target,int sum,int n) {
    // cout << sum << " " << n << " " << endl;
    if(n >= numbers.size()){
        if(sum == target) total++;
        return;
    }
    // cout << "dfs 1-1 start <<<<< "<< n << endl;
    DFS(numbers, target, sum + numbers[n], n+1);
    // cout << "dfs 1-1 end <<<<< " << endl;
    // cout << "dfs 1-2 start <<<<< "<< sum << " " << n << endl;
    DFS(numbers, target, sum - numbers[n], n+1);
    // cout << "dfs 1-2 end <<<<< " << endl;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    // cout << "dfs 1 start <<<<< " << endl;
    DFS(numbers, target, numbers[0] , 1);
    // cout << "dfs 1 end <<<<< " << endl;
    // cout << "dfs 2 start <<<<< " << endl;
    DFS(numbers, target, -numbers[0], 1);
    // cout << "dfs 1 end <<<<< " << endl;

    answer = total;

    return answer;
}
```


## java

```
class Solution {
    static int num_len;
    static int answer;
    public int solution(int[] numbers, int target) {
        num_len = numbers.length;
        int idx = 0;
        dfs(0,idx,numbers,"",target);
        return answer;
    }
    
    public static void dfs(int sum, int idx, int[] arr, String str, int target) {
        if(num_len==0) {
            // System.out.println(str+"="+sum);
            if(sum==target) answer++;
            return;
        }

        for(int i=0;i<2;i++) {
            num_len--;
            switch(i){
                case 0:
                    dfs(sum+arr[idx],idx+1,arr,str+"+"+arr[idx],target);
                    break;
                case 1:
                    dfs(sum-arr[idx],idx+1,arr,str+"-"+arr[idx],target);
                    break;
            }
            num_len++;
        }
    }
}
```