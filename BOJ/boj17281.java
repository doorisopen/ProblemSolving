import java.io.*;
import java.util.*;

/*
 * 17281 ⚾
 */
public class boj17281 {
    static final int PLAYER_SIZE = 9;
    static int N, answer = 0;
    static int[][] board;
    static boolean[] check = new boolean[9];
    static boolean[] field = new boolean[4];
    static List<Integer> selectedPlayer = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        setPlayer();
        System.out.println(answer);
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        N = Integer.parseInt(br.readLine());
        board = new int[N][9];
        String[] input;
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < input.length; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void setPlayer() {
        if (selectedPlayer.size() == PLAYER_SIZE) {
            int gameScore = gameStart();
            // System.out.println(selectedPlayer.toString()+ "=>" + gameScore);
            answer = Math.max(answer, gameScore);
        }
        for (int i = 0; i < PLAYER_SIZE; i++) {
            if ((i == 0) && (selectedPlayer.size() < 3)) continue;
            if (selectedPlayer.size() == 4) {
                if (selectedPlayer.get(3) != 0) continue;
            }
            if (!check[i]) {
                check[i] = true;
                selectedPlayer.add(i);
                setPlayer();
                check[i] = false;
                selectedPlayer.remove(selectedPlayer.size()-1);
            }
        }
    }

    public static int gameStart() {
        int gameScore = 0;
        int pos = 0;
        for (int i = 0; i < N; i++) {
            int roundScore = 0;
            int outCount = 0;
            field = new boolean[4];
            while (outCount < 3) {
                int player = selectedPlayer.get(pos++);
                int score = calcScore(board[i][player]);
                if (score == -1) {
                    outCount++;
                } else {
                    roundScore += score;
                }
                if (pos == PLAYER_SIZE)  {
                    pos = 0;
                }
            }
            gameScore += roundScore;
        }
        return gameScore;
    }

    public static int calcScore(int roundResult) {
        int score = 0;
        if (roundResult == 0) return -1;
        if (roundResult == 4) score++;
        for (int i = 3; i >= 1; i--) {
            if (field[i]) {
                if ((i+roundResult) > 3) {
                    score++;
                } else {
                    field[i+roundResult] = true;
                }
                field[i] = false;
            }
        }
        if (roundResult < 4) {
            field[roundResult] = true;
        }
        return score;
    }
}
