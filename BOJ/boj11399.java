import java.io.*;
import java.util.*;

/*
 * 11399 ATM
 */
public class boj11399 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.sort(arr);
        int answer = 0;
        int time = 0;
        for (int i = 0; i < N; i++) {
            time += arr[i];
            answer += time;
        }
        System.out.println(answer);
    }
}
