import java.io.*;
import java.util.*;

/*
 * 10830 행렬 제곱
 */
public class boj10830 {
    static StringBuffer sb = new StringBuffer();
    static final int MOD = 1000;
    static int N;
    static long B;
    static long[][] matrix;
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
        B = Long.parseLong(input[1]);
        matrix = new long[N][N];
        for (int i = 0; i < N; i++) {
            String[] arr = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                matrix[i][j] = Integer.parseInt(arr[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        long[][] res = power(matrix, B);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(res[i][j]+" ");
            }
            sb.append("\n");
        }
    }

    public static long[][] power(long[][] a, long b) {
        long[][] res = new long[N][N];
        long[][] temp = new long[N][N];
        if (b == 1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    res[i][j] = (a[i][j] % MOD);
                }
            }
        } else if (b % 2 == 1) {
            temp = power(a, b-1);
            res = mul(a, temp);
        } else {
            long[][] half = power(a, b/2);
            res = mul(half, half);
        }
        return res;
    }

    public static long[][] mul(long[][] matrixA, long[][] matrixB) {
        long[][] res = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int j2 = 0; j2 < N; j2++) {
                    res[i][j] += ((matrixA[i][j2]%MOD) * (matrixB[j2][j]%MOD))%MOD;
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }
}
