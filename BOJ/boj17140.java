import java.io.*;
import java.util.*;

/*
 * 17140 이차원 배열과 연산
 */
class Data implements Comparable<Data> {
    int num;
    int count;

    Data(int num, int count) {
        this.num = num;
        this.count = count;
    }

    @Override
    public int compareTo(Data o) {
        if (this.count < o.count) {
            return -1;
        } else if (this.count == o.count) {
            if (this.num < o.num) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}
public class boj17140 {
    static int r, c, k;
    static int[][] board = new int[500][500];
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Scanner sc = new Scanner(System.in);
        //TO-DO
        r = sc.nextInt();
        c = sc.nextInt();
        k = sc.nextInt();
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        int time = 0;
        int row = 3, col = 3;
        while (board[r][c] != k) {
            // System.out.println(time + " = " + row + " " + col);
            // printBoard(row, col);
            if (time > 100) break;
            if (row >= col) {
                col = calcR(row, col);
            } else {
                row = calcC(row, col);
            }
            time++;
        }
        if (time > 100) {
            System.out.println(-1);
        } else {
            System.out.println(time);
        }
    }

    public static int calcR(int row, int col) {
        int mxSize = 0;
        for (int i = 1; i <= row; i++) {
            Map<Integer, Integer> numCount = new TreeMap<>();
            for (int j = 1; j <= col; j++) {
                int key = board[i][j];
                if (key == 0) continue;
                if (numCount.containsKey(key)) {
                    numCount.put(key, numCount.get(key)+1);
                } else {
                    numCount.put(key, 1);
                }
            }
            mxSize = Math.max(mxSize, setRBoard(i, numCount));
        }
        return mxSize;
    }

    public static int calcC(int row, int col) {
        int mxSize = 0;
        for (int i = 1; i <= col; i++) {
            Map<Integer, Integer> numCount = new TreeMap<>();
            for (int j = 1; j <= row; j++) {
                int key = board[j][i];
                if (key == 0) continue;
                if (numCount.containsKey(key)) {
                    numCount.put(key, numCount.get(key)+1);
                } else {
                    numCount.put(key, 1);
                }
            }
            mxSize = Math.max(mxSize, setCBoard(i, row, numCount));
        }
        return mxSize;
    }

    public static int setRBoard(int i, Map<Integer, Integer> numCount) {
        List<Data> list = new ArrayList<>();
        for (Integer key : numCount.keySet()) {
            list.add(new Data(key, numCount.get(key)));
        }
        Collections.sort(list);
        List<Integer> temp = new ArrayList<>();
        for (int j = 0; j < list.size(); j++) {
            temp.add(list.get(j).num);
            temp.add(list.get(j).count);
        }
        //init
        board[i] = new int[500];
        for (int j = 0; j < temp.size(); j++) {
            board[i][j+1] = temp.get(j);
        }
        return temp.size();
    }

    public static int setCBoard(int i, int j, Map<Integer, Integer> numCount) {
        List<Data> list = new ArrayList<>();
        for (Integer key : numCount.keySet()) {
            list.add(new Data(key, numCount.get(key)));
        }
        Collections.sort(list);
        List<Integer> temp = new ArrayList<>();
        for (int k = 0; k < list.size(); k++) {
            temp.add(list.get(k).num);
            temp.add(list.get(k).count);
        }
        //init
        for (int k = 0; k <= j; k++) {
            board[k][i] = 0;
        }
        for (int k = 0; k < temp.size(); k++) {
            board[k+1][i] = temp.get(k);
        }
        return temp.size();
    }

    public static void printBoard(int row, int col) {
        System.out.println("======");
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
