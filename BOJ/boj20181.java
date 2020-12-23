import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
/*
 * 20181 꿈틀꿈틀 호석 애벌레 - 효율성
 */
public class boj20181 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        String[] input = br.readLine().split(" ");
        int[] info = new int[2];
        for (int i = 0; i < input.length; i++) {
            info[i] = Integer.parseInt(input[i]);
        }
        int n = info[0];
        int k = info[1];
        input = br.readLine().split(" ");
        int[] food = new int[n + 1];
        for (int i = 0; i < n; i++) {
            food[i + 1] = Integer.parseInt(input[i]);
        }
        // search
        int r = 0;
        long cur = 0, mx = 0;
        long[] dp = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            mx = Math.max(mx, dp[i - 1]);
            while (r <= n && cur < k) {
                cur += food[r++];
            }
            dp[r - 1] = Math.max(dp[r - 1], mx + Math.max(0, cur - k));
            cur -= food[i];
        }
        long result = Arrays.stream(dp).max().getAsLong();
		System.out.println(result);
		br.close();
	}
}