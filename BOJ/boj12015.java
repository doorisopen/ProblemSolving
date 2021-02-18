import java.io.*;
import java.util.*;

/*
 * 12015 가장 긴 증가하는 부분 수열2
 */
public class boj12015 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[] seq;

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
        seq = new int[N];
        String[] input = br.readLine().split(" ");
        int pos = 0;
        for (int i = 0; i < N; i++) {
            int target = Integer.parseInt(input[i]);
            if (pos == 0 || (seq[pos-1] < target)) {
                seq[pos++] = target;
            } else {
                seq[lower_bound(target, pos)] = target;
            }
        }
        System.out.println(pos);
        //END
        sc.close();
		br.close();
    }

    public static int lower_bound(int target, int size) {
        int l = 0;
        int r = size;
        while (l < r) {
            int mid = (l+r)/2;
            if (seq[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}
