import java.io.*;
import java.util.*;

/*
 * 1912 연속합
 */
public class boj1912 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] arr;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // StringTokenizer st = new StringTokenizer(br.readLine());
        //TO-DO
        N = Integer.parseInt(br.readLine());
        arr = new int[N+1];
        dp = new int[N+1];
        String[] input = br.readLine().split(" ");
        for (int j = 0; j < N; j++) {
            arr[j] = Integer.parseInt(input[j]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int mx = Integer.MIN_VALUE;
        dp[0] = arr[0];
        for (int i = 1; i < N; i++) {
            dp[i] = Math.max(dp[i-1] + arr[i], arr[i]);
            mx = Math.max(mx, dp[i]);
        }
        mx = Math.max(mx, dp[0]);
        System.out.println(mx);
    }
}
