import java.io.*;
import java.util.*;

/*
 * 5430 AC
 */
public class boj5430 {
    static StringBuffer sb = new StringBuffer();
    static int t;
    
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
        t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] command = br.readLine().split("");
            int n = Integer.parseInt(br.readLine());
            String input = br.readLine();
            String[] temp = input.substring(1,input.length()-1).split(",");
            Deque<Integer> dq = new LinkedList<>();
            for (int j = 0; j < n; j++) {
                dq.add(Integer.parseInt(temp[j]));
            }
            sb.append(solve(command, dq));
        }
        //END
        sc.close();
		br.close();
    }

    public static String solve(String[] cmd, Deque<Integer> dq) {
        boolean isReverse = false;
        for (int i = 0; i < cmd.length; i++) {
            if (cmd[i].equals("R")) {
                isReverse = !isReverse;
            } else if (cmd[i].equals("D")) {
                if (dq.size() == 0) return "error\n";
                if (isReverse) {
                    dq.removeLast();
                } else {
                    dq.removeFirst();
                }
            }
        }
        List<String> result = new ArrayList<>();
        if (isReverse) {
            Collections.reverse((List<?>) dq);
        }
        while (!dq.isEmpty()) {
            result.add(dq.pollFirst().toString());
        }
        return "["+String.join(",", result) + "]\n";
    }
}
