import java.io.*;
import java.util.*;

/*
 * 9375 패션왕 신해빈
 */
public class boj9375 {
    static StringBuffer sb = new StringBuffer();
    static int T;
    static Map<String, List<String>> closet = new HashMap<>();
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) { 
            int N = Integer.parseInt(br.readLine());
            for (int j = 0; j < N; j++) {
                String[] input = br.readLine().split(" ");
                if (closet.containsKey(input[1])) {
                    closet.get(input[1]).add(input[0]);
                } else {
                    closet.put(input[1], new ArrayList<>());
                    closet.get(input[1]).add(input[0]);
                }
            }
            solve();
            closet.clear();
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int count = 1;
        for (String key : closet.keySet()) {
            count *= (closet.get(key).size() + 1);
        }
        System.out.println(count - 1);
    }
}
