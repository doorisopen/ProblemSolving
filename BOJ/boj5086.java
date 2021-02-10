import java.io.*;
import java.util.*;

/*
 * 5086 배수와 약수
 */
public class boj5086 {
    static StringBuffer sb = new StringBuffer();


    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        while (true) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            if (a == 0 && b == 0) break;
            System.out.println(solve(a, b));
        }
        
        //END
        sc.close();
		br.close();
    }

    public static String solve(int a, int b) {
        if (b%a == 0) {
            return "factor";
        } else if (a%b == 0) {
            return "multiple";
        }
        return "neither";
    }
}
