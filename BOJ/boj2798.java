import java.io.*;
import java.util.*;

/*
 * 2798 블랙잭
 */
public class boj2798 {
    static int N, M, result = 0;
    static String[] cards;

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        selectCards();
        System.out.println(result);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        cards = new String[N];
        cards = br.readLine().split(" ");
        //END
        sc.close();
		br.close();
    }

    public static void selectCards() {
        for (int i = 0; i < N-2; i++) {
            for (int j = i+1; j < N-1; j++) {
                for (int j2 = j+1; j2 < N; j2++) {
                    int card1 = Integer.parseInt(cards[i]);
                    int card2 = Integer.parseInt(cards[j]);
                    int card3 = Integer.parseInt(cards[j2]);
                    int cardSum = card1 + card2 + card3;
                    if ((cardSum <= M) && (M - cardSum) < (M - result)) {
                        result = cardSum;
                    }
                }
            }
        }
    }
}
