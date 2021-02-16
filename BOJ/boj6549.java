import java.io.*;
import java.util.*;

/*
 * 6549 히스토그램에서 가장 큰 직사각형
 */
public class boj6549 {
    static StringBuffer sb = new StringBuffer();
    public static void main(String[] args) throws Exception {
        input();
        //TO-DO
        System.out.println(sb);
    }

    public static void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //TO-DO
        // StringTokenizer st = new StringTokenizer(br.readLine());
        while (true) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            if (n == 0) break;
            long[] height = new long[n];
            for (int i = 0; i < n; i++) {
                height[i] = Long.parseLong(input[i+1]);
            }
            solve(height, n-1);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(long[] height, int n) {
        sb.append(histogram(height, 0, n)+"\n");
    }

    public static long histogram(long[] height, int l, int r) {
        if (l == r) return height[l];
        int mid = (l+r)/2;
        // 왼쪽 or 오른쪽에서 잘리는 사각형
        long ret = Math.max(histogram(height, l, mid), histogram(height, mid+1, r));
        // 양쪽에 모두 걸치는 사각형
        int lo = mid, hi = mid + 1;
        long h = Math.min(height[lo], height[hi]);
        ret = Math.max(ret, h*2); // mid~mid+1 : 너비가 2인 사각형으로 초기화
        while (l < lo || hi < r) {
            // 높이가 높은쪽으로 확장
            if (hi < r && (l == lo || height[lo-1] < height[hi+1])) {
                hi++;//오른쪽으로 확장
                h = Math.min(h, height[hi]);
            } else {
                lo--;//왼쪽으로 확장
                h = Math.min(h, height[lo]);
            }
            ret = Math.max(ret, (hi-lo+1)*h);
        }
        return ret;
    }
}
