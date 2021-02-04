import java.io.*;
import java.util.*;

/*
 * N-Queen
 */
public class boj9663 {
    static StringBuffer sb = new StringBuffer();
    static int N, result = 0;
    static int[] board;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        board = new int[N+1];
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.fill(board, -1);
        for (int i = 0; i < N; i++) {
            board[0] = i;
            nQueen(1);
        }
        System.out.println(result);
    }

    public static void nQueen(int depth) {
        if (depth == N) {
            result++;
            return;
        }
        for (int i = 0; i < N; i++) {
            board[depth] = i;
            if (isPossible(depth)) {
                nQueen(depth+1);
            } else {
                board[depth] = -1;
            }
        }
    }

    public static boolean isPossible(int depth) {
       for (int i = 0; i < depth; i++) {
           if (board[i] == board[depth]) { // 같은 행 일때
               return false;
           }
           if (Math.abs(i-depth) == Math.abs(board[i]-board[depth])) {
               return false;
           }
       }
       return true;
    }
}
