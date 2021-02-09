import java.io.*;
import java.util.*;

/*
 * 9251 LCS
 */
public class boj9251 {
    static StringBuffer sb = new StringBuffer();
    static String[] str1;
    static String[] str2;
    static int[][] dp;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // StringTokenizer st = new StringTokenizer(br.readLine());
        //TO-DO
        dp = new int[1001][1001];
        String[] input = br.readLine().split("");
        str1 = new String[input.length+1];
        for (int j = 0; j < input.length; j++) {
            str1[j+1] = input[j];
        }
        input = br.readLine().split("");
        str2 = new String[input.length+1];
        for (int j = 0; j < input.length; j++) {
            str2[j+1] = input[j];
        }
        
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 1; i < str1.length; i++) {
            for (int j = 1; j < str2.length; j++) {
                if (str1[i].equals(str2[j])) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        System.out.println(dp[str1.length-1][str2.length-1]);
    }
}
