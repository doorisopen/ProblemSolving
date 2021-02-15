import java.io.*;
import java.util.*;

/*
 * 1992 쿼드트리
 */
public class boj1992 {
    static StringBuffer sb = new StringBuffer();
    static int n;
    static int[][] board;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        sb.append(solve(n,0,0));
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
            String[] input = br.readLine().split("");
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static String solve(int n, int x, int y) {
        if (isOne(n, x, y)) {
            return "1";
        }
        if (isZero(n, x, y)) {
            return "0";
        }
        return "("+solve(n/2, x, y)
        +solve(n/2, x, y+n/2)
        +solve(n/2, x+n/2, y)
        +solve(n/2, x+n/2, y+n/2)+")";
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
