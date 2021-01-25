import java.util.*;

class 더맵게 {
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        for (int i : scoville) {
            pq.add(i);
        }
        while (pq.peek() < K) {
            if (pq.size() == 1) break;
            int cur = pq.poll();
            int nxt = pq.poll();
            pq.add(cur+(nxt*2));
            answer++;
        }
        if (pq.peek() < K) {
            answer = -1;
        }
        return answer;
    }
}