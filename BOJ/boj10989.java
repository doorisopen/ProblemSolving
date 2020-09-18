/*
 * 10989 수 정렬하기 3
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj10989 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		//input
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[10001];
		for (int i = 0; i < n; i++) {
			arr[Integer.parseInt(br.readLine())]++;
		}

		for (int i = 0; i <= 10000; i++) {
			int cnt = arr[i];
			while(cnt-- > 0) {
				sb.append(i+"\n");
			}
		}
		System.out.println(sb);
		br.close();
	}
}