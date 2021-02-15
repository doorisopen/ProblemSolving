import java.io.*;
import java.util.*;

/*
 * 1780 종이의 개수
 */
public class boj1780 {
    static StringBuffer sb = new StringBuffer();
    static int n, zero = 0, one = 0, minus = 0;
    static int[][] board;
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve(n,0,0);
        sb.append(minus+"\n"+zero+"\n"+one);
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
        if (isMinus(n, x, y)) {
            minus++;
            return;
        }
        if (isZero(n, x, y)) {
            zero++;
            return;
        }
        if (isOne(n, x, y)) {
            one++;
            return;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                solve(n/3, x+(n/3*i), y+(n/3*j));
            }
        }
    }

    public static boolean isOne(int n, int x, int y) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                if (board[i][j] == 0 || board[i][j] == -1) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isZero(int n, int x, int y) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                if (board[i][j] == -1 || board[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isMinus(int n, int x, int y) {
        for (int i = x; i < n+x; i++) {
            for (int j = y; j < n+y; j++) {
                if (board[i][j] == 0 || board[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
}
