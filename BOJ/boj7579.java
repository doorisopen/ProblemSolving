import java.io.*;
import java.util.*;

/*
 * 7579 앱 
 */
public class boj7579 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static int[] on;
    static int[] off;
    static int[] dp = new int[10005];

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
        on = new int[N+1];
        off = new int[N+1];
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            on[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            off[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += off[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = sum; j >= off[i]; j--) {
                dp[j] = Math.max(dp[j], dp[j-off[i]]+on[i]);
            }
        }
        int i;
        for (i = 0; i < sum && dp[i] < M; i++);
        sb.append(i);
    }
}
