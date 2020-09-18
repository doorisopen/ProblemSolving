/*
 * 2751 수 정렬하기 2
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class boj2751 {	
    
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		//input
		int n = Integer.parseInt(br.readLine());
		boolean[] arr = new boolean[2000001];
		for (int i = 0; i < n; i++) {
			arr[Integer.parseInt(br.readLine()) + 1000000] = true;
		}

		for (int i = 0; i <= 2000000; i++) {
			if(arr[i]) {
				sb.append((i-1000000)+"\n");
			}
		}
		System.out.println(sb);
		br.close();
	}
}
