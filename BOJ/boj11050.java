import java.io.*;
import java.util.*;

/*
 * 11050 이항 계수 1
 */
public class boj11050 {
    static StringBuffer sb = new StringBuffer();

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
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        solve(N,K);
        //END
        sc.close();
		br.close();
    }

    public static void solve(int N, int K) {
        int count = 0;
        int tempN = N, tempK = K;
        int denominator = 1;
        int molecule = 1;
        while (count < K) {
            denominator *= (tempN--);
            molecule *= (tempK--);
            count++;
        }
        System.out.println((denominator/molecule));
    }
}
