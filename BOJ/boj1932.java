import java.io.*;
import java.util.*;

/*
 * 1932 정수 삼각형
 */
public class boj1932 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[][] board;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        //TO-DO
        board = new int[N+1][N+1];
        dp = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int j = 0;
            while (st.hasMoreTokens()) {
                board[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int res = 0;
        dp[0][0] = board[0][0];
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i+1][j] = Math.max(dp[i+1][j], board[i+1][j] + dp[i][j]);
                dp[i+1][j+1] = Math.max(dp[i+1][j+1], board[i+1][j+1] + dp[i][j]);
                res = Math.max(res, Math.max(dp[i+1][j], dp[i+1][j+1]));
            }
        }
        System.out.println(res);
    }
}
