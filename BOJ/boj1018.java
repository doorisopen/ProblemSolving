import java.io.*;
import java.util.*;

/*
 * 1018 체스판 다시 칠하기
 */
public class boj1018 {
    static int N, M;
    static String[] board;
    static String[] wb = {"WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW"};
    static String[] bw = {"BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB",
                            "BWBWBWBW",
                            "WBWBWBWB"};
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        board = new String[N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine();
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int result = Integer.MAX_VALUE;
        for (int i = 0; i+8 <= N; i++) {
            for (int j = 0; j+8 <= M; j++) {
                result = Math.min(result, Math.min(calcBlackWhite(i, j), calcWhiteBlack(i, j)));
            }
        }
        System.out.println(result);
    }

    public static int calcWhiteBlack(int x, int y) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[x+i].charAt(y+j) != bw[i].charAt(j)) {
                    count++;
                }
            }
        }
        return count;
    }

    public static int calcBlackWhite(int x, int y) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[x+i].charAt(y+j) != wb[i].charAt(j)) {
                    count++;
                }
            }
        }
        return count;
    }
}
