import java.io.*;
import java.util.*;

/*
 * 2565 전깃줄
 */
public class boj2565 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[][] arr;
    static int[] dp;
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
        arr = new int[N][2];
        dp = new int[N];
        for (int i = 0; i < N; i++) {
            int j = 0;
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                arr[i][j++] = Integer.parseInt(st.nextToken());
            }    
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int res = 0;
        Arrays.sort(arr, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        for (int i = 0; i < N; i++) {
            int curB = arr[i][1];
            int cross = 0;
            for (int j = 0; j < i; j++) {
                int preB = arr[j][1];
                if (curB > preB) {
                    cross = Math.max(cross, dp[j]);
                }
            }
            dp[i] = cross + 1;
            res = Math.max(res, dp[i]);
        }
        System.out.println(N-res);
    }
}
