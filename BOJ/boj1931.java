import java.io.*;
import java.util.*;

/*
 * 1931 회의실 배정
 */
public class boj1931 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static int[][] arr;
    public static void main(String[] args) throws Exception {
        init();
        //TO-DO
        solve();
    }

    public static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // StringTokenizer st = new StringTokenizer(br.readLine());
        //TO-DO
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        arr = new int[N][2];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            arr[i][0] = Integer.parseInt(input[1]);
            arr[i][1] = Integer.parseInt(input[0]);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        Arrays.sort(arr, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                }
                return o1[0] - o2[0];
            }
        });
        int nxt = 0;
        int answer = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i][1] >= nxt) {
                nxt = arr[i][0];
                answer++;
            }
        }
        System.out.println(answer);
    }
}
