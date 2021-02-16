import java.io.*;
import java.util.*;

/*
 * 2740 행렬 곱셈
 */
public class boj2740 {
    static StringBuffer sb = new StringBuffer();
    static int N, M, K;
    static int[][] matrixA = new int[101][101];
    static int[][] matrixB = new int[101][101];
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
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        N = n; M = m;
        for (int i = 0; i < n; i++) {
            String[] arr = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                matrixA[i][j] = Integer.parseInt(arr[j]);
            }
        }

        input = br.readLine().split(" ");
        m = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        for (int i = 0; i < m; i++) {
            String[] arr = br.readLine().split(" ");
            for (int j = 0; j < K; j++) {
                matrixB[i][j] = Integer.parseInt(arr[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                int sum = 0;
                for (int j2 = 0; j2 < M; j2++) {
                    sum += (matrixA[i][j2] * matrixB[j2][j]);
                }
                sb.append(sum+" ");
            }
            sb.append("\n");
        }
    }
}
