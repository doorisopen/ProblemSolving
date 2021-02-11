import java.io.*;
import java.util.*;

/*
 * 2004 조합 0의 개수
 */
public class boj2004 {
    static StringBuffer sb = new StringBuffer();
    static long[][] dp;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        long N = Integer.parseInt(input[0]);
        long M = Integer.parseInt(input[1]);
        solve(N,M);
        //END
        sc.close();
		br.close();
    }

    public static void solve(long N, long M) {
        int[] n = calc(N);
        int[] m = calc(M);
        int[] nm = calc(N-M);
        int two = n[0] - (m[0] + nm[0]);
        int five = n[1] - (m[1] + nm[1]);
        System.out.println(Math.min(two, five));
    }

    public static int[] calc(long number) {
        int two = 0, five = 0;
        for (long i = 2; i <= number; i*=2) {
            two += (number/i);
        }
        for (long i = 5; i <= number; i*=5) {
            five += (number/i);
        }
        return new int[]{two,five};
    }
}
