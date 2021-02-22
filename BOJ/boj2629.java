import java.io.*;
import java.util.*;

/*
 * 2629 양팔저울
 */
public class boj2629 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static int[] w1;
    static int[] w2;
    static int[][] dp = new int[40][50005];

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
        N = Integer.parseInt(br.readLine());
        w1 = new int[N+1];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            w1[i] = Integer.parseInt(input[i]);
        }
        M = Integer.parseInt(br.readLine());
        w2 = new int[M+1];
        input = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            w2[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 0; i < N+1; i++) {
            Arrays.fill(dp[i],-1);
        }
        calc(0,0);
        for (int i = 0; i < M; i++) {
            if (dp[N][w2[i]] == 1) {
                sb.append("Y ");
            } else if (w2[i] > 15000) {
                sb.append("N ");
            } else {
                sb.append("N ");
            }
        }
    }
    
    public static void calc(int count, int weight) {
        if (count > N) return;
        if (dp[count][weight] != -1) return;
        dp[count][weight] = 1;
        calc(count+1, weight+w1[count]); // 구슬이 없는 쪽에 올리는 경우
        calc(count+1, weight); // 양쪽에 추를 안올리는 경우
        calc(count+1, Math.abs(weight-w1[count])); // 구슬이 있는 쪽에 올리는 경우
    }
}
