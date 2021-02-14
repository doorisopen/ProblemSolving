import java.io.*;
import java.util.*;

/*
 * 1966 프린터 큐
 */
public class boj1966 {
    static StringBuffer sb = new StringBuffer();
    static int t;

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
        t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] input = br.readLine().split(" ");
            String[] arr = br.readLine().split(" ");
            LinkedList<int[]> queue = new LinkedList<>();
            for (int j = 0; j < Integer.parseInt(input[0]); j++) {
                queue.add(new int[]{j,Integer.parseInt(arr[j])});
            }
            solve(queue, Integer.parseInt(input[1]));
        }
        //END
        sc.close();
		br.close();
    }

    public static void solve(List<int[]> queue, int target) {
        int count = 1;
        while (queue.size() > 0) {
            while (isBigger(queue)) {
                queue.add(queue.remove(0));
            }
            if (queue.get(0)[0] == target) break;
            queue.remove(0);
            count++;
        }
        sb.append(count+"\n");
    }

    public static boolean isBigger(List<int[]> queue) {
        for (int i = 1; i < queue.size(); i++) {
            if (queue.get(0)[1] < queue.get(i)[1]) {
                return true;
            }
        }
        return false;
    }
}
