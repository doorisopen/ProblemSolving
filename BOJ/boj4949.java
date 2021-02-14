import java.io.*;
import java.util.*;

/*
 * 4949 균형잡힌 세상
 */
public class boj4949 {
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        // solve();
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        while (true) {
            String input = br.readLine();
            if (input.length() == 1 && input.charAt(0) == '.') break;
            solve(input);
        }
        System.out.println(sb);
        //END
        sc.close();
		br.close();
    }

    public static void solve(String input) {
        List<Character> regex = Arrays.asList('(','[',')',']');
        Stack<Character> stack = new Stack<>();
        int len = input.length();
        int small = 0;
        int big = 0;
        boolean isPass = true;
        for (int i = 0; i < len; i++) {
            if (!regex.contains(input.charAt(i))) continue;
            if (input.charAt(i) == '(') {
                stack.add('(');
                small++;
            } else if (input.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    isPass = false;
                    break;
                }
                if (stack.peek() == '(') {
                    stack.pop();
                    small--;
                } else {
                    isPass = false;
                    break;
                }
            }
            if (input.charAt(i) == '[') {
                stack.add('[');
                big++;
            } else if (input.charAt(i) == ']') {
                if (stack.isEmpty()) {
                    isPass = false;
                    break;
                }
                if (stack.peek() == '[') {
                    stack.pop();
                    big--;
                } else {
                    isPass = false;
                    break;
                }
            }
            if (small < 0 || big < 0) {
                isPass = false;
                break;
            }
        }
        if (!isPass || small != 0 || big != 0) {
            sb.append("no\n");
        } else {
            sb.append("yes\n");
        }
    }
}
