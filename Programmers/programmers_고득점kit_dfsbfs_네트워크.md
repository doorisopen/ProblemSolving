
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/43162)

## c++

```
class Solution {

    public void dfs(int s, int[][] computers, boolean[] v) {
        v[s] = true;
        for(int i = 0; i < computers.length; i++) {
            if(computers[s][i] == 1 && !v[i]) {
                dfs(i,computers,v);
            }
        }
    }
    public int solution(int n, int[][] computers) {
        boolean[] v = new boolean[n];
        int answer = 0;
        for(int i = 0; i < computers.length; i++) {
            if(!v[i]) {
                answer++;
                dfs(i,computers,v);
            }
        }
        return answer;
    }
}
```