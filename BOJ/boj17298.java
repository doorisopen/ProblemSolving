import java.io.*;
import java.util.*;

/*
 * 17298 오큰수
 */
public class boj17298 {
    static StringBuffer sb = new StringBuffer();
    static int n;
    static int[] ans = new int[1000001];
    static int[] arr = new int[1000001];
    static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.peek()] < arr[i]) {
                ans[stack.pop()] = arr[i];
            }
            stack.push(i);
        }

        //result
        for (int i = 0; i < n; i++) {
            sb.append(ans[i]+" ");
        }
        System.out.println(sb);
    }
}
