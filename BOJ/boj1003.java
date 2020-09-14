/**
 * boj 1003 피보나치 함수
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj1003 {
	private static Integer[] dp = new Integer[41]; 
	public static int fibo(int n) {
		if(n == 0) return 1;
		if(n == 1) return 1;
		if(dp[n] != null) return dp[n];
		return dp[n] = fibo(n-1) + fibo(n-2);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcase = Integer.parseInt(br.readLine());
		for (int i = 0; i < testcase; i++) {
			int num = Integer.parseInt(br.readLine());
			if(num == 0) {
				System.out.println("1 0");
			} else if(num == 1) {
				System.out.println("0 1");
			} else {
				System.out.println(fibo(num-2) + " " + fibo(num-1));
			}
		}
		br.close();
	}
}
