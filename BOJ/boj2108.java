import java.io.*;
import java.util.*;

/*
 * 2108 통계학
 */
public class boj2108 {
    static int N;
    static int[] arr;
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
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Integer.parseInt(br.readLine());
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve() {
        arithmeticMean();
        median();
        mode();
        range();
    }

    public static void arithmeticMean() {
        int[] temp = arr;
        int sum = Arrays.stream(temp).sum();
        System.out.println(Math.round((double)sum/(double)N));
    }

    public static void median() {
        int[] temp = arr;
        Arrays.sort(temp);
        System.out.println(temp[N/2]);
    }

    public static void mode() {
        int[] temp = new int[1000001];
        int[] checkFreqDuplicate = new int[1000001];

        for (int i = 0; i < N; i++) {
            int idx = (arr[i]+500000);
            temp[idx] += 1;
        }
        PriorityQueue<Mode> pq = new PriorityQueue<>();
        for (int i = 0; i < 1000001; i++) {
            if (temp[i] > 0) {
                pq.add(new Mode(temp[i], i-500000));
                checkFreqDuplicate[temp[i]]++;
            }
        }
        int modeNum = 0;
        // System.out.println("---");
        while (!pq.isEmpty()) {
            int num = pq.peek().num;
            int idx = num+500000;
            // System.out.println(idx+"=>"+temp[idx]);
            if (checkFreqDuplicate[temp[idx]] > 1) { // 중복 되는 경우
                pq.poll();
                modeNum = pq.peek().num;
            } else {
                modeNum = num;
            }
            break;
        }
        System.out.println(modeNum);
    }

    public static void range() {
        int[] temp = arr;
        Arrays.sort(temp);
        System.out.println((temp[N-1] - temp[0]));
    }

    public static class Mode implements Comparable<Mode> {
        int num;
        int freq;

        Mode(int freq, int num) {
            this.freq = freq;
            this.num = num;
        }

        @Override
        public int compareTo(boj2108.Mode o) {
            if (o.freq > this.freq) {
                return 1;
            } else if (o.freq == this.freq){
                if (o.num < this.num) {
                    return 1;
                } else {
                    return -1;
                }
            }
            return -1;
        }
    }
}
