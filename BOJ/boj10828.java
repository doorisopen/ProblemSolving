/*
 * 10828 스택
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj10828 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Stack<Integer> s = new Stack<Integer>();
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0) {
			String[] command = br.readLine().split(" ");
			if(command[0].equals("push")) {
				s.push(Integer.valueOf(command[1]));
			} else if(command[0].equals("pop")) {
				if(s.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(s.peek()+"\n");
					s.pop();
				}
			} else if(command[0].equals("size")) {
				sb.append(s.size()+"\n");
			} else if(command[0].equals("empty")) {
				if(s.isEmpty()) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			} else if(command[0].equals("top")) {
				if(s.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(s.peek()+"\n");
				}
			}
		}
		System.out.println(sb);
		br.close();
	}
}