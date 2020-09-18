/*
 * 1920 수 찾기
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class boj1920 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		//input
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];

		String[] str = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(str[i]);
		}

		//input
		int m = Integer.parseInt(br.readLine());
		String[] check = br.readLine().split(" ");
		
		//sort
		Arrays.sort(arr);

		//search
		for (int i = 0; i < m; i++) {
			int num = Integer.parseInt(check[i]);
			if(Arrays.binarySearch(arr, num) >= 0) {
				sb.append("1\n");
			} else {
				sb.append("0\n");
			}
		}
		System.out.println(sb);
		br.close();
	}
}
