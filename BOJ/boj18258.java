import java.io.*;
import java.util.*;

/*
 * 18258 큐2
 */
public class boj18258 {
    static StringBuffer sb = new StringBuffer();
    static int n, end = -1;
    static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            solve(input);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(String[] input) {
        if (input[0].equals("push")) {
            int num = Integer.parseInt(input[1]);
            queue.add(num);
            end = num;
        } else if (input[0].equals("pop")) {
            if (queue.isEmpty()) {
                sb.append("-1\n");
            } else {
                sb.append(queue.poll()+"\n");
            }
        } else if (input[0].equals("size")) {
            sb.append(queue.size()+"\n");
        } else if (input[0].equals("empty")) {
            if (queue.isEmpty()) {
                sb.append("1\n");
            } else {
                sb.append("0\n");
            }
        } else if (input[0].equals("front")) {
            if (queue.isEmpty()) {
                sb.append("-1\n");
            } else {
                sb.append(queue.peek()+"\n");
            }
        } else { // back
            if (queue.isEmpty()) {
                sb.append("-1\n");
            } else {
                sb.append(end+"\n");
            }
        }
    }
}
