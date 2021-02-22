import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 11049 행렬 곱셈 순서
 */
public class boj11049 {
    private static final StringBuffer sb = new StringBuffer();
    static int[][] arr;
    static int[] preMul;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        System.out.println(sb);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(br.readLine());
        arr = new int[N+1][2];
        preMul = new int[N+1];
        dp = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 2; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }
        for (int j = 0; j < N; j++) {
            Arrays.fill(dp[j], -1);
        }
        solve(N);
    }

    public static void solve(int n) {
        int ans = calc(0, n-1);
        sb.append(ans+"\n");
    }

    public static int calc(int s, int e) {
        if (s == e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        int ret = Integer.MAX_VALUE;
        if (e == s+1) {
            return arr[s][0] * arr[s][1] * arr[e][1];
        }
        for (int i = s; i < e; i++) {
            int mul = arr[s][0] * arr[i][1] * arr[e][1];
            ret = Math.min(ret, calc(s, i) + calc(i+1, e) + mul);
        }
        return dp[s][e] = ret;
    }
}
