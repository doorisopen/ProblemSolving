/*
 * 2750 수 정렬하기
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
public class boj2750 {
    
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		//input
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		//sort
		Arrays.sort(arr);

		for (int i = 0; i < n; i++) {
			sb.append(arr[i]+"\n");
		}
		System.out.println(sb);
		br.close();
    }
}