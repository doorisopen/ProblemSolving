import java.io.*;
import java.util.*;

/*
 * 17406 배열 돌리기 4
 */
public class boj17406 {
    static final int INF = 999999999;
    static int N, M, K, result = INF;
    static String[][] board;
    static String[][] buffer;
    static String[][] command;
    static boolean[] checkOrder;
    static List<Integer> selectedOrder = new LinkedList<>();
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        selectOrder();
        System.out.println(result);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);
        K = Integer.parseInt(str[2]);
        board = new String[N][M];
        buffer = new String[N][M];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().split(" ");
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                buffer[i][j] = board[i][j];
            }
        }
        command = new String[K][3];
        checkOrder = new boolean[K];
        for (int i = 0; i < K; i++) {
            command[i] = br.readLine().split(" ");
        }
        //END
        sc.close();
		br.close();
    }

    public static void selectOrder() {
        if (selectedOrder.size() == K) {
            initBoard();
            int idx = 0;
            for (int i = 0; i < K; i++) {
                idx = selectedOrder.get(i);
                rotate(command[idx][0], command[idx][1], command[idx][2]);
            }
            result = Math.min(result, calc());
        }
        for (int i = 0; i < K; i++) {
            if (!checkOrder[i]) {
                checkOrder[i] = true;
                selectedOrder.add(i);
                selectOrder();
                checkOrder[i] = false;
                selectedOrder.remove(selectedOrder.size()-1);
            }
        }
    }

    public static void initBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = buffer[i][j];
            }
        }
    }

    public static int calc() {
        int mnSum = INF;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += Integer.parseInt(board[i][j]);
            }
            mnSum = Math.min(mnSum, sum);
        }
        return mnSum;
    }

    public static void rotate(String r, String c, String s) {
        int R = Integer.parseInt(r);
        int C = Integer.parseInt(c);
        int S = Integer.parseInt(s);
        // (R-S, C-S) ~ (R+S, C+S)
        int startX = (R-S)-1;
        int startY = (C-S)-1;
        int endX = (R+S)-1;
        int endY = (C+S)-1;
        while ((startX != endX) && (startY != endY)) {
            int curX = startX;
            int curY = startY;
            String temp = board[curX][curY];
            int move = 0;
            while (move < 4) {
                int nx = curX + dx[move];
                int ny = curY + dy[move];
                if (isRange(nx, ny, startX, startY, endX, endY)) {
                    if ((move == 3) && (nx == startX && ny == startY)) {
                        board[curX][curY] = temp;
                    } else {
                        board[curX][curY] = board[nx][ny];
                    }
                    curX = nx; curY = ny;
                } else {
                    move++;
                }
            }
            startX += 1; startY += 1;
            endX -= 1; endY -= 1;
        }
    }

    public static boolean isRange(int cx, int cy, int sx, int sy, int ex, int ey) {
        if ((cx < sx) || (cy < sy) || (cx > ex) || (cy > ey)) {
            return false;
        }
        return true;
    }

    public static void printBoard() {
        System.out.println("===rotate result===");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
