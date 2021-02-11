import java.io.*;
import java.util.*;

/*
 * 11051 이항 계수 2
 */
public class boj11051 {
    static StringBuffer sb = new StringBuffer();
    static long[][] dp;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        dp = new long[N+1][K+1];
        dp[N][K] = solve(N,K);
        System.out.println(dp[N][K]);
        //END
        sc.close();
		br.close();
    }

    public static long solve(int N, int K) {
        if (dp[N][K] > 0) return dp[N][K];
        if (K == 0 || N == K) return 1;
        // 파스칼 삼각형 참고
        // (a+b)%mod = (a%mod + b%mod)%mod
        return dp[N][K] = (solve(N-1, K-1) + solve(N-1, K)) % 10007;
    }
}
