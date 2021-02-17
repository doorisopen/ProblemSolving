import java.io.*;
import java.util.*;

/*
 * 10816 숫자 카드 2
 */
public class boj10816 {
    static StringBuffer sb = new StringBuffer();
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(br.readLine());
        arr = new int[20000001];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[Integer.parseInt(input[i])+10000000]++;
        }

        M = Integer.parseInt(br.readLine());
        input = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            int x = Integer.parseInt(input[i]);
            sb.append(arr[x+10000000]+" ");
        }
        //END
        sc.close();
		br.close();
    }
    
    public static void solve() {
    }
}
