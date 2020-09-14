/**
 * boj 1463 1로 만들기
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj1463 {
	private static int[] dp; 
	public static int calc(int n) {
		if(n == 1) return 0;
		if(dp[n] > 0) return dp[n];
		dp[n] = calc(n-1)+1;
		if(n % 3 == 0) dp[n] = Math.min(dp[n],calc(n/3)+1);
		if(n % 2 == 0) dp[n] = Math.min(dp[n],calc(n/2)+1);
		return dp[n];
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		dp = new int[num+1];
		System.out.println(calc(num));
		br.close();
	}
}
