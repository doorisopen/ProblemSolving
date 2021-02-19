import java.io.*;
import java.util.*;

/*
 * 1655 가운데를 말해요
 */
public class boj1655 {
    static StringBuffer sb = new StringBuffer();
    static int N;
    static PriorityQueue<Integer> mnPq = new PriorityQueue<>();
    static PriorityQueue<Integer> mxPq = new PriorityQueue<>(Comparator.reverseOrder());

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
        N = Integer.parseInt(br.readLine());
        while (N-- > 0) {
            int num = Integer.parseInt(br.readLine());
            solve(num);
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(int num) {
        if (mnPq.size() == mxPq.size()) {
            if (mnPq.size() == 0 && mxPq.size() == 0) {
                mxPq.add(num);
            } else {
                if (mnPq.peek() < num) {
                    int temp = mnPq.poll();
                    mnPq.add(num);
                    mxPq.add(temp);
                } else {
                    mxPq.add(num);
                }
            }
        } else if (mnPq.size() < mxPq.size()) {
            if (mxPq.peek() > num) {
                int temp = mxPq.poll();
                mxPq.add(num);
                mnPq.add(temp);
            } else {
                mnPq.add(num);
            }
        }
        sb.append(mxPq.peek()+"\n");
    }
}
