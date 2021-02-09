import java.io.*;
import java.util.*;

/*
 * 11054 가장 긴 바이토닉 부분 수열
 */
public class boj11054 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] arr;
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
        arr = new int[N+1];
        dp = new int[2][N+1];
        st = new StringTokenizer(br.readLine());
        int i = 0;
        while (st.hasMoreTokens()) {
            arr[i++] = Integer.parseInt(st.nextToken());
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int res = 0;
        Arrays.fill(dp[0], 1);
        Arrays.fill(dp[1], 1);
        asc();
        desc();
        for (int i = 0; i < N; i++) {
            res = Math.max(res, (dp[0][i] + dp[1][i] - 1));
        }
        System.out.println(res);
    }

    public static void asc() {
        for (int i = 0; i < N; i++) {
            int mx = 0;
            for (int left = 0; left < i; left++) {
                if (arr[i] > arr[left]) {
                    mx = Math.max(mx, dp[0][left]);
                }
            }
            dp[0][i] = mx + 1;
        }
    }

    public static void desc() {
        for (int i = N-1; i >= 0; i--) {
            int mx = 0;
            for (int right = N-1; right > i; right--) {
                if (arr[i] > arr[right]) {
                    mx = Math.max(mx, dp[1][right]);
                }
            }
            dp[1][i] = mx + 1;
        }
    }
}
