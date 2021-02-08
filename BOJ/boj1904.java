import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 1904 01타일 
 */
public class boj1904 {
    static int N;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        init();
        int result = solve(N);
        System.out.println(result);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = Integer.parseInt(br.readLine());
        dp = new int[1100000];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 5;
        // 1 1
        // 2 00 11
        // 3 001 100 111
        // 4 1100 0011 1001 1111 0000
        // 5 00000 01100 00110 11100 01110 10011 11001 11111
    }

    public static int solve(int num) {
        if (dp[num] != 0) return dp[num];
        return dp[num] = (solve(num-1) + solve(num-2))%15746;
    }
}
