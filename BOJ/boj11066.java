import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 11066 파일 합치기
 */
public class boj11066 {
    private static final StringBuffer sb = new StringBuffer();
    static int[] cost;
    static int[] preSum;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        System.out.println(sb);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            cost = new int[N+1];
            preSum = new int[N+1];
            dp = new int[N+1][N+1];
            for (int j = 0; j < N; j++) {
                Arrays.fill(dp[j], -1);
            }
            for (int j = 0; j < N; j++) {
                cost[j] = Integer.parseInt(input[j]);
            }
            for (int j = 1; j <= N; j++) {
                preSum[j] = preSum[j-1] + cost[j-1];
            }
            solve(N);
        }
    }

    public static void solve(int n) {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n-1; i++) {
            ans = Math.min(ans, (calc(0, i) + calc(i+1, n-1)));
        }
        sb.append(ans+"\n");
    }

    public static int calc(int s, int e) {
        if (s == e) return cost[s];
        if (dp[s][e] != -1) return dp[s][e];
        int ret = Integer.MAX_VALUE;
        int sum = preSum[e+1] - preSum[s];
        for (int i = s; i < e; i++) {
            ret = Math.min(ret, calc(s, i) + calc(i+1, e) + sum);
        }
        return dp[s][e] = ret;
    }
}
