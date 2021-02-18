import java.io.*;
import java.util.*;

/*
 * 2110 공유기 설치
 */
public class boj2110 {
    static StringBuffer sb = new StringBuffer();
    static int N, C;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        solve();
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        // 1 2 4 8 9
        int left = 1;
        int right = arr[N-1] - arr[0];
        sb.append(search(left, right));
    }

    public static int search(int l, int r) {
        int ans = 0;
        while (l <= r) {
            int cur = arr[0];
            int count = 1;
            int mid = (l + r) / 2;// 현재 간격으로 설치
            int dist = 0;//
            for (int i = 1; i < N; i++) {
                dist = arr[i] - cur;
                if (mid <= dist) {
                    count++;
                    cur = arr[i];
                }
            }
            if (count >= C) {// 간격 넓히기
                ans = mid;// 최대 간격
                l = mid+1;
            } else { // 간격 좁히기
                r = mid-1;
            }
        }
        return ans;
    }
}
