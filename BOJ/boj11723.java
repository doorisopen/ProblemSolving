/*
 * 11723 집합
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class boj11723 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		//input
		int n = Integer.parseInt(br.readLine());
		int val = 0;
		for (int i = 0; i < n; i++) {
			String[] cmd = br.readLine().split(" ");
			if(cmd[0].equals("add")) {
				if((val & (1<<Integer.parseInt(cmd[1]))) > 0) {
					continue;
				} else {
					val |= (1<<Integer.parseInt(cmd[1]));
				}
			} else if(cmd[0].equals("remove")) {
				if((val & (1<<Integer.parseInt(cmd[1]))) > 0) {
					val ^= (1<<Integer.parseInt(cmd[1]));
				}
			} else if(cmd[0].equals("check")) {
				if((val & (1<<Integer.parseInt(cmd[1]))) > 0) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			} else if(cmd[0].equals("toggle")) {
				if((val & (1<<Integer.parseInt(cmd[1]))) > 0) {
					val ^= (1<<Integer.parseInt(cmd[1]));
				} else {
					val |= (1<<Integer.parseInt(cmd[1]));
				}
			} else if(cmd[0].equals("all")) {
				for (int j = 1; j <= 20; j++) {
					if((val & (1<<j)) == 0) {
						val |= (1<<j);
					}
				}
			} else if(cmd[0].equals("empty")) {
				val = 0;
			}
		}
		System.out.println(sb);
		br.close();
	}
}