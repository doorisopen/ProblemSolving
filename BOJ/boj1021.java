import java.io.*;
import java.util.*;

/*
 * 1021 회전하는 큐
 */
public class boj1021 {
    static StringBuffer sb = new StringBuffer();
    static int n, m, ans = 0;
    static Deque<Integer> dq = new LinkedList<>();
    
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        System.out.println(ans);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            dq.add(i+1);
        }
        for (int i = 0; i < m; i++) {
            solve(Integer.parseInt(input[i]));
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(int pos) {
        Deque<Integer> l = new LinkedList<>(dq);
        Deque<Integer> r = new LinkedList<>(dq);
        if (dq.peekFirst() == pos) {
            dq.removeFirst();
        } else {
            int lcnt = 0;
            int rcnt = 0;
            while (l.peekFirst() != pos) {
                l.addLast(l.removeFirst());
                lcnt++;
            }
            while (r.peekFirst() != pos) {
                r.addFirst(r.removeLast());
                rcnt++;
            }
            if (lcnt < rcnt) {
                dq = l;
                ans += lcnt;
            } else {
                dq = r;
                ans += rcnt;
            }
            dq.removeFirst();
        }
    }
}
