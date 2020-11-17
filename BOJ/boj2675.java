/*
 * 2675 문자열 반복
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj2675 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String[] str = br.readLine().split(" ");
			String answer = "";
			int cnt = Integer.parseInt(str[0]);
			for (int j = 0; j < str[1].length(); j++) {
				for (int j2 = 0; j2 < cnt; j2++) {
					answer += str[1].charAt(j);					
				}
			}
			sb.append(answer+"\n");
		}
		System.out.println(sb);
		br.close();
	}
}