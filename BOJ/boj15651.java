import java.io.*;
import java.util.*;

/*
 * N과 M (3)
 */
public class boj15651 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        arr = new int[N+1];
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        nm(0);
        System.out.println(sb);
    }

    public static void nm(int d) {
        if (d == M) {
            for (int i = 0; i < M; i++) {
                sb.append(arr[i]+" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 1; i <= N; i++) {
            arr[d] = i;
            nm(d+1);
        }
    }
}
