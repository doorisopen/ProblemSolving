import java.util.*;

class 기능개발 {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        //set data
        int len = progresses.length;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < len; i++) {
            int remain = (100-progresses[i]);
            int deploy = remain/speeds[i];
            if ((remain%speeds[i]) > 0) {
                deploy++;
            }
            q.add(deploy);
        }
        
        //calc data
        int idx = 0;
        int[] temp = new int[10001];
        int cur = q.poll();
        temp[idx] = 1;
        while (!q.isEmpty()) {
            int nxt = q.poll();
            if (cur >= nxt) {
                temp[idx]++;
            } else {
                idx++;
                temp[idx] = 1;
                cur = nxt;
            }
        }
        
        //result
        answer = new int[idx+1];
        for (int i = 0; i <= idx; i++) {
            answer[i] = temp[i];
        }
        return answer;
    }
}