import java.io.*;
import java.util.*;

/*
 * 5648 역원소 정렬
 */
public class boj5648 {
    static int N;
    static String[] numbers;
    static long[] temp;
    
    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = sc.nextInt();
        numbers = new String[N];
        temp = new long[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = sc.next();
        }
        for (int i = 0; i < N; i++) {
            sb.append(numbers[i]);
            temp[i] = Long.parseLong(sb.reverse().toString());
            sb.delete(0, sb.length());
        }
        sc.close();
		br.close();
    }

    public static void main(String[] args) throws Exception {
        init();
        Arrays.sort(temp);
        for (int i = 0; i < N; i++) {
            System.out.println(temp[i]);
        }
    }
}