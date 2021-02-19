import java.io.*;
import java.util.*;

/*
 * 11286 절댓값 힙
 */
public class boj11286 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
        @Override
        public int compare(int[] o1, int[] o2) {
            if (o1[0] == o2[0]) {
                return (o1[1] - o2[1]);
            }
            return (o1[0] - o2[0]);
        }
    });

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            int num = Integer.parseInt(br.readLine());
            solve(num);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(int num) {
        if (num == 0) {
            if (pq.isEmpty()) {
                sb.append("0\n");
            } else {
                int[] cur = pq.poll();
                sb.append(cur[1]+"\n");
            }
        } else {
            pq.add(new int[]{Math.abs(num), num});
        }
    }
}
