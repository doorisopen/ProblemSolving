import java.io.*;
import java.util.*;

/*
 * 1300 K번째 수
 * n*n행렬이 주어질때, 1~n행 까지 mid 값 보다 작은 수들의 개수(j의 개수) 구하기
 * 0*0 ~ i*j ≤ mid ⇒ j ≤ mid/i
 */
public class boj1300 {
    static StringBuffer sb = new StringBuffer();
    static int N, K;

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
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int ans = 0;        
        int l = 1;
        int r = K;
        while (l <= r) {
            long count = 0;
            int mid = (l+r)/2;
            // i*j <= mid 일때, j <= mid/i 이다.
            for (int i = 1; i <= N; i++) {
                count += Math.min(mid/i, N);
            }
            if (count < K) { // mid 보다 작거나 같은 수가 K보다 적을때
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        sb.append(ans);
    }
}
