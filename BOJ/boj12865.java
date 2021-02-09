import java.io.*;
import java.util.*;

/*
 * 12865 평범한 배낭
 */
public class boj12865 {
    static StringBuffer sb = new StringBuffer();
    static int N, K;
    static int[][] arr;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // StringTokenizer st = new StringTokenizer(br.readLine());
        //TO-DO
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        arr = new int[N+1][2];
        dp = new int[N+1][100005];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            arr[i+1][0] = Integer.parseInt(input[0]);//무게
            arr[i+1][1] = Integer.parseInt(input[1]);//가치
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (j - arr[i][0] >= 0) {
                    // 이전 배낭의 무게, 현재 물건의 무게를 뺀 이전 배낭 + 현재 물건의 가치
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j - arr[i][0]] + arr[i][1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        System.out.println(dp[N][K]);
    }
}
