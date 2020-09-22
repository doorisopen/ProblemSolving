/*
 * 10866 덱
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class boj10866 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Deque<Integer> dq = new ArrayDeque<Integer>();
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0) {
			String[] command = br.readLine().split(" ");
			if(command[0].equals("push_back")) {
				dq.add(Integer.valueOf(command[1]));
			} else if(command[0].equals("push_front")) {
				dq.addFirst(Integer.valueOf(command[1]));
			} else if(command[0].equals("pop_back")) {
				if(dq.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(dq.removeLast()+"\n");
				}
			} else if(command[0].equals("pop_front")) {
				if(dq.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(dq.removeFirst()+"\n");
				}
			} else if(command[0].equals("size")) {
				sb.append(dq.size()+"\n");
			} else if(command[0].equals("empty")) {
				if(dq.isEmpty()) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			} else if(command[0].equals("back")) {
				if(dq.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(dq.peekLast()+"\n");
				}
			} else if(command[0].equals("front")) {
				if(dq.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(dq.peekFirst()+"\n");
				}
			}
		}
		System.out.println(sb);
		br.close();
	}
}