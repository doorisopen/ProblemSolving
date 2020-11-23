/*
 * 2908 상수
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj2908 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		String[] input = br.readLine().split(" ");
		String a = "", b = "";
		for (int i = input[0].length()-1; i >= 0; i--) {
			a += input[0].charAt(i);
		}
		for (int i = input[1].length()-1; i >= 0; i--) {
			b += input[1].charAt(i);
		}
		if(Integer.parseInt(a) > Integer.parseInt(b)) {
			sb.append(a);
		} else {
			sb.append(b);
		}
		System.out.println(sb);
		br.close();
	}
}