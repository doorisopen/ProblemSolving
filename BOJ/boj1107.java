/*
 * 1107 리모콘
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj1107 {

	static boolean[] check = new boolean[10];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		String[] bronken;
		if(M > 0) {
			bronken = br.readLine().split(" ");
			for (int i = 0; i < bronken.length; i++) {
				check[Integer.parseInt(bronken[i])] = true;
			}
		}
		int answer = Math.abs(N-100);
		for (int i = 0; i <= 1000000; i++) {
			if(M == 10) break;
			int checkNum = brute(i);
			if(checkNum == -1) continue;
			int count = Math.abs(N-i);
			answer = Math.min(answer, count + checkNum);
		}
		System.out.println(answer);
		br.close();
	}
	private static int brute(int N) {
		int temp = N;
		int count = 0;
		while(true) {
			int val = temp%10;
			if(check[val]) break;
			temp /= 10;
			count++;
			if(temp == 0) return count;
		}
		return -1;
	}
}