import java.io.*;
import java.util.*;

/*
 * 2293 동전
 */
public class boj2293 {
    static StringBuffer sb = new StringBuffer();
    static int N, K;
    static int[] coin;
    static int[] dp = new int[10005];

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        coin = new int[N+1];
        for (int i = 0; i < N; i++) {
            coin[i] = Integer.parseInt(br.readLine());
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= K; j++) {
                if (j-coin[i] >= 0) {
                    dp[j] += dp[j-coin[i]];
                }
            }
        }
        sb.append(dp[K]);
    }
}
