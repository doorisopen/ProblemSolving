import java.io.*;
import java.util.*;

/*
 * 1010 다리 놓기
 */
public class boj1010 {
    static StringBuffer sb = new StringBuffer();
    static int T;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(br.readLine());
        dp = new int[31][31];
        for (int i = 0; i < T; i++) { 
            String[] input = br.readLine().split(" ");
            int K = Integer.parseInt(input[0]);
            int N = Integer.parseInt(input[1]);   
            dp[N][K] = solve(N,K);
            System.out.println(dp[N][K]);
        }
        //END
        sc.close();
		br.close();
    }

    public static int solve(int N, int K) {
        if (dp[N][K] > 0) return dp[N][K];
        if (K == 0 || N == K) return 1;
        return dp[N][K] = solve(N-1, K-1) + solve(N-1, K);
    }
}
