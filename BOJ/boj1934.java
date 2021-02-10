import java.io.*;
import java.util.*;

/*
 * 1934 최소공배수
 */
public class boj1934 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            solve(a,b);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(int a, int b) {
        System.out.println((a*b)/gcd(a,b));
    }

    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
}
