import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 11053 가장 긴 증가하는 부분 수열
 */
public class boj11053 {
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
        arr = new int[N+1];
        dp = new int[N+1];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
    }

    public static void solve() {
        Arrays.fill(dp, 1);
        int res = 0;
        for (int i = 0; i < N; i++) {
            int mx = 0;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    mx = Math.max(mx, dp[j]);
                }
            }
            dp[i] = mx + 1;
            res = Math.max(res, dp[i]);
        }
        System.out.println(res);
    }
}
