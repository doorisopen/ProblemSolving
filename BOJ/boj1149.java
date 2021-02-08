import java.io.*;
import java.util.*;

/*
 * 1149 RGB거리
 */
public class boj1149 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[][] rgb;
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
        rgb = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int j = 0;
            while (st.hasMoreTokens()) {
                rgb[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 0; i < N; i++) {
            rgb[i+1][0] = rgb[i+1][0] + Math.min(rgb[i][1], rgb[i][2]);
            rgb[i+1][1] = rgb[i+1][1] + Math.min(rgb[i][0], rgb[i][2]);
            rgb[i+1][2] = rgb[i+1][2] + Math.min(rgb[i][0], rgb[i][1]);
        }
        int res = Math.min(rgb[N-1][0], Math.min(rgb[N-1][1], rgb[N-1][2]));
        System.out.println(res);
    }
}
