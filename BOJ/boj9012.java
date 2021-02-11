import java.io.*;
import java.util.*;

/*
 * 9012 괄호
 */
public class boj9012 {
    static StringBuffer sb = new StringBuffer();
    static int N;

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
        N = Integer.parseInt(br.readLine());
        while ((N--) != 0) {
            String input = br.readLine();
            solve(input);
        }
        System.out.println(sb);
        //END
        sc.close();
		br.close();
    }

    public static void solve(String input) {
        int len = input.length();
        int status = 0;
        boolean isPass = true;
        for (int i = 0; i < len; i++) {
            if (input.charAt(i) == '(') {
                status++;
            } else {
                status--;
            }
            if (status < 0) {
                isPass = false;
                break;
            }
        }
        if (!isPass || status != 0) {
            sb.append("NO\n");
        } else {
            sb.append("YES\n");
        }
    }
}
