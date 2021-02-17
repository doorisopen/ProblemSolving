import java.io.*;
import java.util.*;

/*
 * 2805 나무 자르기
 */
public class boj2805 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static long mx = 0;
    static long[] woods;

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
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        woods = new long[N];
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            long num = Long.parseLong(input[i]);
            mx = Math.max(mx, num);
            woods[i] = num;
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        long l = 0, r = mx, ans = 0;
        while (l <= r) {
            long mid = (l+r)/2;
            long cut = 0;
            for (int i = 0; i < N; i++) {
                if (woods[i] > mid) {
                    cut += (woods[i]-mid);
                }
            }
            if (cut >= M) {
                ans = Math.max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        sb.append(ans);
    }
}
