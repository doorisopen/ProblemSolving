import java.io.*;
import java.util.*;

/*
 * 11660 구간 합 구하기 5
 */
public class boj11660 {
    static int N, M;
    static int[][] board;
    static int[][] boundary;

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        calcBoundarySum();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = sc.nextInt();
        M = sc.nextInt();
        board = new int[N+1][N+1];
        boundary = new int[M][4];
        int num;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                num = sc.nextInt();
                board[i+1][j+1] = board[i+1][j] + board[i][j+1] - board[i][j] + num;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 4; j++) {
                boundary[i][j] = sc.nextInt();
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void calcBoundarySum() {
        for (int i = 0; i < M; i++) {
            int x1 = boundary[i][0];
            int y1 = boundary[i][1];
            int x2 = boundary[i][2];
            int y2 = boundary[i][3];
            int sum = board[x2][y2] - board[x1 - 1][y2] - board[x2][y1 - 1] + board[x1 - 1][y1 - 1];
            System.out.println(sum);
        }
    }
}
