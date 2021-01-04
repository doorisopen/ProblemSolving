import java.io.*;
import java.util.*;

/*
 * 11652 카드
 */
public class boj11652 {
    static int N;
    static long[] cards;
    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        cards = new long[N];
        for (int i = 0; i < N; i++) {
            cards[i] = sc.nextLong();            
        }
        sc.close();
		br.close();
    }

    public static void main(String[] args) throws Exception {
        StringBuffer sb = new StringBuffer();
        init();
        Arrays.sort(cards);
        long result = 1L;
        int count = 1, mxCount = 0;
        for (int i = 0; i < N-1; i++) {
            if (cards[i] == cards[i+1]) {
                count++;
            } else {
                count = 1;
            }
            if (mxCount < count) {
                mxCount = count;
                result = cards[i];
            }
        }
        System.out.println(result);
    }
}