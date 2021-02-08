import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 2156 포도주 시식
 */
public class boj2156 {
    static int N;
    static int[] w;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        init();
        solve(N);
        System.out.println(dp[N]);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(br.readLine());
        w = new int[N+1];
        dp = new int[N+1];
        for (int i = 0; i < N; i++) {
            w[i+1] = Integer.parseInt(br.readLine());
        }
    }

    public static void solve(int num) {
        // dp[i] = Math.max(w[i]+w[i-1]+dp[i-3], w[i]+dp[i-1])
        dp[0] = 0;
        dp[1] = w[1];
        if (num >= 2) {
            dp[2] = w[1] + w[2];
        }
        for (int i = 3; i <= N; i++) {
            dp[i] = Math.max(w[i]+w[i-1]+dp[i-3], w[i]+dp[i-2]);
            dp[i] = Math.max(dp[i], dp[i-1]);
        }
    }
}
