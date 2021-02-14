import java.io.*;
import java.util.*;

/*
 * 11866 요세푸스 문제0
 */
public class boj11866 {
    static StringBuffer sb = new StringBuffer();
    static int n, k;
    static LinkedList<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int pos = 0;
        List<String> ans = new ArrayList<>();
        while (n-- > 0) {
            if (pos+k-1 < queue.size()) {
                pos += (k-1);
                ans.add(Integer.toString(queue.remove(pos)));
            } else if (pos+k-1 == queue.size()-1) {
                pos = queue.size() - 1;
                ans.add(Integer.toString(queue.remove(pos)));
                pos = queue.size() - 1;
            } else {
                pos = (pos+(k-1))%queue.size();
                ans.add(Integer.toString(queue.remove(pos)));
            }
        }

        String result = "<";
        result += String.join(", ", ans);
        result += ">";
        System.out.println(result);
    }
}
