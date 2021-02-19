import java.io.*;
import java.util.*;

/*
 * 11279 최대 힙
 */
public class boj11279 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

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
                sb.append(pq.poll()+"\n");
            }
        } else {
            pq.add(num);
        }
    }
}
