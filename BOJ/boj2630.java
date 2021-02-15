import java.io.*;
import java.util.*;

/*
 * 2630 색종이 만들기
 */
public class boj2630 {
    static StringBuffer sb = new StringBuffer();
    static int n, blue = 0, white = 0;
    static int[][] board;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve(n,0,0);
        sb.append(white+"\n"+blue);
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        for (int i = 0; i < board.length; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(int n, int x, int y) {
        if (isOne(n, x, y)) {
            blue++;
            return;
        }
        if (isZero(n, x, y)) {
            white++;
            return;
        }
        solve(n/2, x, y);
        solve(n/2, x, y+n/2);
        solve(n/2, x+n/2, y);
        solve(n/2, x+n/2, y+n/2);
    }

    public static boolean isOne(int n, int x, int y) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isZero(int n, int x, int y) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                if (board[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
}
