import java.io.*;
import java.util.*;

/*
 * 9184 신나는 함수 실행
 */
public class boj9184 {
    static StringBuffer sb = new StringBuffer();
    static int[][][] dp = new int[51][51][51];
    static List<int[]> arr = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        while (true) {
            String[] input = br.readLine().split(" ");
            if (input[0].equals("-1") && 
            input[1].equals("-1") && 
            input[2].equals("-1")) break;
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int c = Integer.parseInt(input[2]);
            arr.add(new int[]{a,b,c});
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        for (int i = 0; i < arr.size(); i++) {
            int[] abc = arr.get(i);
            int result = w(abc[0],abc[1],abc[2]);
            System.out.println("w("+abc[0]+", "+abc[1]+", "+abc[2]+") = "+result);
        }
    }

    public static int w(int a, int b, int c){
        if ((a <= 0) || (b <= 0) || (c <= 0)) return 1;
        if (dp[a][b][c] > 0) return dp[a][b][c];
        if (a > 20 || b > 20 || c > 20) return dp[a][b][c] = w(20,20,20);
        if (a < b && b < c) return dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
        return dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
}
