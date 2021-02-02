import java.io.*;
import java.util.*;

/*
 * 2231 분해합
 */
public class boj2231 {
    static int N;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        search();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        //END
        sc.close();
		br.close();
    }

    public static void search() {
        int result = 1000001;
        for (int i = N; i >= 0; i--) {
            int temp = i;
            int M = i;
            while (temp != 0) {
                M += (temp % 10);
                temp /= 10;
            }
            if (M == N) {
                result = Math.min(result, i);
            }
        }
        if (result == 1000001) result = 0;
        System.out.println(result);
    }
}
