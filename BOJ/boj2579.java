import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 2579 계단 오르기 
 */
public class boj2579 {
    static int N;
    static int[] arr;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        init();
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(br.readLine());
        arr = new int[10001];
        dp = new int[10001];
        for (int i = 0; i < N; i++) {
            arr[i+1] = Integer.parseInt(br.readLine());
        }
    }

    public static void solve() {
        // n, n-1, n-3
        // n, n-2
        dp[0] = 0;
        dp[1] = arr[1];
        if (N >= 2) {
            dp[2] = arr[2]+dp[1];
        }
        for (int i = 3; i <= N; i++) {
            dp[i] = Math.max(arr[i-1] + dp[i-3], dp[i-2]) + arr[i];
        }
        System.out.println(dp[N]);
    }
}
