import java.io.*;
import java.util.*;

/*
 * 1654 랜선 자르기
 */
public class boj1654 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static long sum = 0;
    static long[] arr;

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
        M = Integer.parseInt(input[1]);
        arr = new long[N];
        for (int i = 0; i < N; i++) {
            long num = Long.parseLong(br.readLine());
            sum += num;
            arr[i] = num;
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        long avg = sum/M;
        long l = 1, r = avg, ans = 0;
        while (l <= r) {
            long mid = (l+r)/2;
            long cnt = 0;
            for (int i = 0; i < N; i++) {
                cnt += (arr[i]/mid);
            }
            if (cnt >= M) {
                ans = Math.max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        sb.append(ans);
    }
}
