import java.io.*;
import java.util.*;

/*
 * 2580 스도쿠
 */
public class boj2580 {
    static StringBuffer sb = new StringBuffer();
    static int[][] board;
    static List<int[]> blank = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        board = new int[9][9];
        for (int i = 0; i < 9; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < input.length; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                if (board[i][j] == 0) {
                    blank.add(new int[]{i,j});
                }
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        sudoku(0);
    }

    public static void sudoku(int d) {
        if (d == blank.size()) {
            //print
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board.length; j++) {
                    sb.append(board[i][j]+" ");
                }
                sb.append("\n");
            }
            System.out.println(sb);
            System.exit(0);
        }
        for (int i = 1; i <= 9; i++) {
            int x = blank.get(d)[0];
            int y = blank.get(d)[1];
            if (isPossible(x, y, i)) {
                board[x][y] = i;
                sudoku(d+1);
                board[x][y] = 0;
            }
        }
    }

    public static boolean isPossible(int x, int y, int num) {
        // 행
        for (int i = 0; i < board.length; i++) {
            if (board[i][y] == num) return false;
        }
        // 열
        for (int i = 0; i < board.length; i++) {
            if (board[x][i] == num) return false;
        }
        // 네모
        int startX = (x/3)*3;
        int startY = (y/3)*3;
        for (int i = startX; i < startX+3; i++) {
            for (int j = startY; j < startY+3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }
}
