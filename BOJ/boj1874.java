import java.io.*;
import java.util.*;

/*
 * 1874 스택 수열
 */
public class boj1874 {
    static StringBuffer sb = new StringBuffer();
    static int nxt = 1;
    static List<Integer> arr = new ArrayList<>();
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        for (int i = 0; i < arr.size(); i++) {
            boolean result = solve(arr.get(i));
            if (!result) {
                System.out.println("NO\n");
                return;
            }    
        }
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int input = Integer.parseInt(br.readLine());
            arr.add(input);
        }
        
        //END
        sc.close();
		br.close();
    }

    public static boolean solve(int input) {
        //add
        if (nxt <= input) {
            while (nxt <= input) {
                stack.add(nxt++);
                sb.append("+\n");
            }
        }
        if (stack.isEmpty()) return false;
        if (stack.peek() > input) {
            while (stack.peek() != input) {
                stack.pop();
                sb.append("-\n");
            }
        }
        if (stack.peek() == input) {
            stack.pop();
            sb.append("-\n");
        }
        return true;
    }
}
