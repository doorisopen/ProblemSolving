import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 10942 팰린드롬?
 */
public class boj10942 {
    private static final StringBuffer sb = new StringBuffer();
    static int[] arr;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        System.out.println(sb);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(br.readLine());
        arr = new int[N+1];
        dp = new int[N+1][N+1];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i+1] = Integer.parseInt(input[i]);
        }
        for (int j = 0; j < N; j++) {
            Arrays.fill(dp[j], -1);
        }
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int s = Integer.parseInt(input[0]);
            int e = Integer.parseInt(input[1]);
            sb.append(solve(s, e)+"\n");
        }
    }

    public static int solve(int s, int e) {
        if (s >= e) return 1;
        if (dp[s][e] != -1) return dp[s][e];
        if (arr[s] == arr[e]) {
            return dp[s][e] = solve(s+1, e-1);
        } else {
            return 0;
        }
    }
}
