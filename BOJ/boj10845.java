/*
 * 10845 큐
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class boj10845 {

	static int lastItem;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Queue<Integer> q = new LinkedList<Integer>();
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0) {
			String[] command = br.readLine().split(" ");
			if(command[0].equals("push")) {
				q.add(Integer.valueOf(command[1]));
				lastItem = Integer.parseInt(command[1]);
			} else if(command[0].equals("pop")) {
				if(q.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(q.poll()+"\n");
				}
			} else if(command[0].equals("size")) {
				sb.append(q.size()+"\n");
			} else if(command[0].equals("empty")) {
				if(q.isEmpty()) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			} else if(command[0].equals("front")) {
				if(q.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(q.peek()+"\n");
				}
			} else if(command[0].equals("back")) {
				if(q.isEmpty()) {
					sb.append("-1\n");
				} else {
					sb.append(lastItem+"\n");
				}
			}
		}
		System.out.println(sb);
		br.close();
	}
}