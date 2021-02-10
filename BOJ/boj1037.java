import java.io.*;
import java.util.*;

/*
 * 1037 약수
 */
public class boj1037 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] factors;

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        factors = new int[N];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            factors[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.sort(factors);
        System.out.println((factors[0]*factors[N-1]));
    }
}
