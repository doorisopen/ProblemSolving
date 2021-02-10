import java.io.*;
import java.util.*;

/*
 * 3036 링
 */
public class boj3036 {
    static StringBuffer sb = new StringBuffer();
    static int N, mn = Integer.MAX_VALUE;
    static int[] numbers;

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
        N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        numbers = new int[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 1; i < N; i++) {
            int res = gcd(numbers[0], numbers[i]);
            System.out.println((numbers[0]/res)+"/"+(numbers[i]/res));
        }
    }

    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
}
