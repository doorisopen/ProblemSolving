import java.io.*;
import java.util.*;

/*
 * 2164 카드2
 */
public class boj2164 {
    static StringBuffer sb = new StringBuffer();
    static int n;
    static LinkedList<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        while (queue.size() != 1) {
            queue.removeFirst();
            queue.addLast(queue.removeFirst());
        }
        sb.append(queue.get(0));
    }
}
