import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 1520 내리막길
 */
public class boj1520 {
    private static final StringBuffer sb = new StringBuffer();
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int N, M;
    static int[][] board;
    static int[][] visit;

    public static void main(String[] args) throws Exception {
        init();
        System.out.println(solve(0, 0));
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        board = new int[N+1][M+1];
        visit = new int[N+1][M+1];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                visit[i][j] = -1;
            }
        }
    }

    public static int solve(int x, int y) {
        if (x == N-1 && y == M-1) return 1;
        if (visit[x][y] == -1) {
            visit[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (board[nx][ny] < board[x][y]) {
                    visit[x][y] += solve(nx,ny);
                }
            }
        }
        return visit[x][y];
    }
}
