import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 9461 파도반 수열
 */
public class boj9461 {
    static int N;
    static long[] dp;
    public static void main(String[] args) throws Exception {
        init();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(br.readLine());
        dp = new long[200];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;
        dp[7] = 4;
        dp[8] = 5;
        dp[9] = 7;
        dp[10] = 9;
        // 0 1 1 1 2 2 3 4 5 7 9
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            long result = solve(num);
            System.out.println(result);
        }
    }

    public static long solve(int num) {
        if (dp[num] >= 0) return dp[num];
        return dp[num] = solve(num-2) + solve(num-3);
    }
}
