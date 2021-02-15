import java.io.*;
import java.util.*;

/*
 * 1629 곱셈
 * https://www.acmicpc.net/board/view/2249
 */
public class boj1629 {
    static StringBuffer sb = new StringBuffer();
    static int a, b, c;
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
        String[] input = br.readLine().split(" ");
        a = Integer.parseInt(input[0]);
        b = Integer.parseInt(input[1]);
        c = Integer.parseInt(input[2]);
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        System.out.println(pow(a,b,c));
    }

    public static long pow(long x, long y, long mod) {
        long ret = 1;
        while (y > 0) {
            if (y%2>0) {
                ret *= x;
                ret %= mod;
            }
            x *= x;
            x %= mod;
            y /= 2;
        }
        return ret;
    }
}
