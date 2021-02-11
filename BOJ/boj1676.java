import java.io.*;
import java.util.*;

/*
 * 1676 팩토리얼 0의 개수
 */
public class boj1676 {
    static StringBuffer sb = new StringBuffer();
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(br.readLine());
        solve(N);
        //END
        sc.close();
		br.close();
    }

    public static void solve(int N) {
        // 54321 = 120
        // 6 = 720 1개
        // 10 = 3628800 2개
        // 25 = 15511210043330985984000000 5+1개
        // 125 = 25+5+1개
        System.out.println((N/5)+(N/25)+(N/125));
    }
}
