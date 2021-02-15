import java.io.*;
import java.util.*;

/*
 * 11401 이항 계수3
 * https://www.acmicpc.net/board/view/15795
 */
public class boj11401 {
    static StringBuffer sb = new StringBuffer();
    static final long MOD = 1000000007L;
    static final int MAX = 4000000;
    static int n, k;
    static long[] factorial;
    static long[] inverse;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        if (n == k || k == 0) {
            sb.append("1");
        } else {
            long res = factorial[n] * inverse[n-k] % MOD;
            res = (res * inverse[k]) % MOD;
            sb.append(res);
        }
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        factorial = new long[MAX+1];
        inverse = new long[MAX+1];
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        // factorial 전처리
        factorial[1] = 1;
        for (int i = 2; i <= MAX; i++) {
            factorial[i] = (factorial[i-1] * i) % MOD;
        }
        //페르마의 소정리를 이용하여 fac(400만)의 inverse를 구함
        //이때 분할 정복을 이용하여 logP의 시간에 처리
        inverse[MAX] = pow(factorial[MAX], MOD - 2);
        for (int i = MAX-1; i > 0; i--) {
            inverse[i] = (inverse[i+1] * (i+1)) % MOD;
        }
    }

    public static long pow(long x, long y) {
        long ret = 1;
        while (y > 0) {
            if (y%2>0) {
                ret *= x;
                ret %= MOD;
            }
            x *= x;
            x %= MOD;
            y /= 2;
        }
        return ret;
    }
}
