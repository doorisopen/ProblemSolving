import java.io.*;
import java.util.*;

/*
 * 14889 스타트와 링크
 */
public class boj14889 {
    static StringBuffer sb = new StringBuffer();
    static int N, result = Integer.MAX_VALUE;
    static int[][] board;
    static boolean[] isSelected;
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
        board = new int[N][N];
        isSelected = new boolean[N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < input.length; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        selectPlayer(0,0);
        System.out.println(result);
    }

    public static void selectPlayer(int count, int idx) {
        if (count == N/2) {
            int startTeam = 0;
            int linkTeam = 0;
            for (int i = 0; i < N; i++) {
                for (int j = i; j < N; j++) {
                    if (isSelected[i] && isSelected[j]) {
                        startTeam += (board[i][j] + board[j][i]);
                    }
                    else if (!isSelected[i] && !isSelected[j]) {
                        linkTeam += (board[i][j] + board[j][i]);
                    }
                }
            }
            result = Math.min(result, Math.abs(startTeam-linkTeam));
            return;
        }

        for (int i = idx; i < N; i++) {
            if (!isSelected[i]) {
                isSelected[i] = true;
                selectPlayer(count+1, i);
                isSelected[i] = false;
            }
        }
    }
}
