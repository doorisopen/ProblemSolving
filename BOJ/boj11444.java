import java.io.*;
import java.util.*;

/*
 * 11444 피보나치 수 6
 * https://www.acmicpc.net/blog/view/28
 */
public class boj11444 {
    static StringBuffer sb = new StringBuffer();
    static final int MOD = 1000000007;
    static long N;
    static long[][] A = {{1,1},{1,0}};
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(br.readLine());
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        // (Fn+1) = (1 1)^n * (F1)
        // (Fn  )   (1 0)     (F0)
        // ---
        // (Fn  ) = (1 1)^n-1 * (F1)
        // (Fn-1)   (1 0)       (F0)
        if (N == 1) {
            sb.append(1);
        } else {
            long[][] res = power(A, N-1);
            sb.append(res[0][0]);
        }
        System.out.println(sb);
    }

    public static long[][] power(long[][] a, long b) {
        long[][] res = {{1,0},{0,1}}; // init
        long[][] temp = a;
        while (b > 0) {
            if (b%2 == 1) {
                res = mul(res, temp);
            }
            temp = mul(temp, temp);
            b /= 2;
        }
        return res;
    }

    public static long[][] mul(long[][] matrixA, long[][] matrixB) {
        long[][] res = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int j2 = 0; j2 < 2; j2++) {
                    res[i][j] += (matrixA[i][j2] * matrixB[j2][j]);
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }
}
