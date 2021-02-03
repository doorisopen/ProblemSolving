import java.io.*;
import java.util.*;

/*
 * 1427 소트인사이드
 */
public class boj1427 {
    static String N;
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
        N = br.readLine();
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        StringBuffer sb = new StringBuffer();
        char[] cStr = N.toCharArray();
        Arrays.sort(cStr);
        for (int i = cStr.length-1; i >= 0; i--) {
            sb.append(cStr[i]);
        }
        System.out.println(sb);
    }
}
