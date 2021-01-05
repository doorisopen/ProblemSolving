import java.io.*;
import java.util.*;

/*
 * 7795 먹은 것인가 먹힐 것인가
 */
public class boj7795 {

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        int n = Integer.parseInt(br.readLine());
        while (n > 0) {
            String input = br.readLine();
            String[] aSet = br.readLine().split(" ");
            String[] bSet = br.readLine().split(" ");
            Integer[] a = new Integer[aSet.length]; 
            Integer[] b = new Integer[bSet.length]; 
            for (int i = 0; i < aSet.length; i++) {
                a[i] = Integer.parseInt(aSet[i]);
            }
            for (int i = 0; i < bSet.length; i++) {
                b[i] = Integer.parseInt(bSet[i]);
            }
            solve(a, b);
            n--;
        }
        sc.close();
		br.close();
    }

    public static void solve(Integer[] a, Integer[] b) {
        Arrays.sort(a, Collections.reverseOrder());
        Arrays.sort(b);
        int matchCount = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                if (a[i] <= b[j]) break;
                matchCount++;
            }
        }
        System.out.println(matchCount);
    }
}
