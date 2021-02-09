import java.io.*;
import java.util.*;

/*
 * 13305 주유소
 */
public class boj13305 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static long[] distance;
    static long[] cost;

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        distance = new long[N];
        cost = new long[N];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N-1; i++) {
            distance[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {            
            cost[i] = Integer.parseInt(input[i]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        long answer = 0;
        long mnFuel = Integer.MAX_VALUE;
        for (int i = 0; i < N-1; i++) {
            mnFuel = Math.min(mnFuel, cost[i]);
            answer += (mnFuel*distance[i]);
        }
        System.out.println(answer);
    }
}
