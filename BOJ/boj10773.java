import java.io.*;
import java.util.*;

/*
 * 10773 제로
 */
public class boj10773 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static Stack<Integer> s = new Stack<>();

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
        int sum = 0;
        while ((N--) != 0) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) {
                if (!s.empty()) {
                    sum -= s.peek();
                    s.pop();
                }
            } else {
                s.add(num);
                sum += s.peek();
            }
        }
        System.out.println(sum);
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        
    }
}
