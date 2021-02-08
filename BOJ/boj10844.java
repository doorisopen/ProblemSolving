import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 10844 쉬운 계단 수
 */
public class boj10844 {
    static int N;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        for (int i = 1; i <= 9; i++) dp[1][i] = 1;
        for (int i = 2; i <= N; i++) {
            solve(i);
        }
        long res = 0;
        for (int i = 0; i <= 9; i++) res += dp[N][i];
        System.out.println(res%1000000000);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(br.readLine());
        dp = new int[N+1][10];
    }

    public static void solve(int len) {
        // 1 -> 1 2 3 4 5 6 7 8 9 : 9개 
        // 2 -> 12 23 34 45 56 67 78 89 : 8개
        //   -> 98 87 76 65 54 43 32 21 10 : 9개 
        for (int i = 0; i <= 9; i++) {
            if (i == 0) {
                dp[len][i] = dp[len-1][i+1];
            } else if (i == 9) {
                dp[len][i] = dp[len-1][i-1];
            } else {
                dp[len][i] = (dp[len-1][i+1] + dp[len-1][i-1]) % 1000000000;
            }
        }
    }
}
